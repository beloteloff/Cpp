
# coding: utf-8

import pandas as pd
import numpy as np
from fbprophet import Prophet
df_plot = pd.read_csv('new-old_LTV.csv',usecols=[0,1,2,3]).iloc[:-4]
df_plot['subsite_id'] = np.nan_to_num(df_plot['subsite_id']).astype(int)
df_plot.tail()
#df_plot.plot(figsize=(25,5),title='SVOD purchase on Samsung',kind='area',color = ['r','b']);
#stacked=True,subplots=True,

table = pd.pivot_table(df_plot,aggfunc=np.sum,columns=['subsite_id'], values=["NewUsers","ReturnUsers"], index=['date'])
table.loc[:, (["NewUsers","ReturnUsers"], 10)]

#table["ReturnUsers"]
#table.dtypes.index
#.loc[:, (slice(None), ('11', '353'))]
#.iloc[:,1]

df = pd.read_csv('svod_tot.csv').sort_values(by='ds',ascending=True,kind='mergesort')
df['y'] = np.log(df['old_users'].replace(0, np.NaN))
#df['y'] = np.log(df['new_users'])
df.pop('new_users')
df.pop('old_users')

#df['cap'] = 8.5
basic_holy = pd.DataFrame({
  'holiday': 'basic',
  'ds': pd.to_datetime(['2017-01-14'
                        #, '2016-01-14', '2015-01-14',
]),
  'lower_window': -1,
  'upper_window': 1,
})
short_holy=pd.DataFrame({
  'holiday': 'short',
    'ds': pd.to_datetime(['2017-05-09','2016-05-09', '2015-05-09',
     '2017-03-08', '2016-03-08', '2015-03-08',
    '2017-02-23', '2016-02-23', '2015-02-23',
    '2017-01-01','2016-01-01', '2015-01-01']),
  'lower_window': 0,
  'upper_window': 2,
})
holy = pd.concat((basic_holy, short_holy))
df

df_plot.corr(method= 'pearson')

#df['cap'] = 0
m = Prophet(holidays=basic_holy).fit(df)
'''holidays=holy
#changepoints=['2016-12-20'],
            seasonality_prior_scale=0.98
            ,holidays_prior_scale=6.9
            ,changepoint_prior_scale=0.0076
            #,interval_width=0.98
            #,mcmc_samples=100'''
           
'''
lg
holidays=holy,
            #changepoints=['2016-12-20'],
            seasonality_prior_scale=0.98
            ,holidays_prior_scale=6.9
            ,changepoint_prior_scale=0.0076
            #,interval_width=0.98
            #,mcmc_samples=100
********************************************************************
parameters_samsung
#changepoints=['2016-12-20']
            seasonality_prior_scale=0.1
            ,holidays_prior_scale=1,
            changepoint_prior_scale=0.055
            #,interval_width=0.9'''          

'''future = m.make_future_dataframe(periods=365)
future['cap'] = 0
fcst = m.predict(future)
m.plot(fcst);'''
future = m.make_future_dataframe(periods=365,freq='D')
future.tail()

forecast = m.predict(future)
m.plot(forecast);

from math import exp
forecast = m.predict(future)
yy=forecast[['ds', 'yhat', 'yhat_lower', 'yhat_upper']]
yy['yhat'] = np.exp(yy['yhat'])
yy['yhat_lower'] = np.exp(yy['yhat_lower'])
yy['yhat_upper'] = np.exp(yy['yhat_upper'])
yy.tail(367)

m.plot_components(forecast);

yy.plot(figsize=(15,6));

df2 = pd.read_csv('svod_tot.csv').sort_values(by='ds',ascending=True,kind='mergesort')
df2['y'] = np.log(df2['new_users'].replace(0, np.NaN))
#df['y'] = np.log(df['new_users'])
df2.pop('new_users')
df2.pop('old_users')

#df['cap'] = 8.5
basic_holy = pd.DataFrame({
  'holiday': 'basic',
  'ds': pd.to_datetime(['2017-01-14'
                        #, '2016-01-14', '2015-01-14',
]),
  'lower_window': -1,
  'upper_window': 1,
})
short_holy=pd.DataFrame({
  'holiday': 'short',
    'ds': pd.to_datetime(['2017-05-09','2016-05-09', '2015-05-09',
     '2017-03-08', '2016-03-08', '2015-03-08',
    '2017-02-23', '2016-02-23', '2015-02-23',
    '2017-01-01','2016-01-01', '2015-01-01']),
  'lower_window': 0,
  'upper_window': 2,
})
holy = pd.concat((basic_holy, short_holy))
mm = Prophet(holidays=basic_holy).fit(df2)
future1 = mm.make_future_dataframe(periods=365,freq='D')
forecast1 = mm.predict(future1)
mm.plot(forecast1);

yyy=forecast1[['ds', 'yhat', 'yhat_lower', 'yhat_upper']]
yyy['yhat'] = np.exp(yyy['yhat'])
yyy['yhat_lower'] = np.exp(yyy['yhat_lower'])
yyy['yhat_upper'] = np.exp(yyy['yhat_upper'])
yyy.tail(367)


add=yy.join(yyy, lsuffix='_old',rsuffix='_new', how='outer')
add

add.plot(figsize=(15,6));

mm.plot_components(forecast1);
