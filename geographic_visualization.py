
# Install required libraries in terminal:
# pip install pandas geopandas folium bokeh

import pandas as pd
import folium

from bokeh.io import show, output_file
from bokeh.models import ColumnDataSource, HoverTool
from bokeh.plotting import figure
from bokeh.layouts import column

# Load the dataset
data = pd.read_csv("geographic.csv")

# Create Bokeh figure
p = figure(
    width=800,
    height=400,
    tools='pan,wheel_zoom,reset'
)

# Create data source
source = ColumnDataSource(data)

# Add circle markers
p.circle(
    x='Longitude',
    y='Latitude',
    size=10,
    source=source,
    color='orange'
)

# Create hover tool
hover = HoverTool(
    tooltips=[
        ("Info", "@Info"),
        ("Latitude", "@Latitude"),
        ("Longitude", "@Longitude")
    ]
)

p.add_tools(hover)

# Display Bokeh plot
layout = column(p)
output_file("bokeh_plot.html")
show(layout)

# Create Folium map
latitude = data['Latitude'].mean()
longitude = data['Longitude'].mean()

m = folium.Map(
    location=[latitude, longitude],
    zoom_start=10
)

# Add markers
for index, row in data.iterrows():
    folium.Marker(
        location=[row['Latitude'], row['Longitude']],
        popup=row['Info']
    ).add_to(m)

# Save the map
m.save("map.html")

print("Geographical visualization completed!")
