import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6
Rectangle{
    property double oldLat:36.897711
    property double oldLng:10.189624
    Plugin{
        id:mapPlugin
        name:  "osm"
    }

   Map{

       id:mapView
       anchors.fill :parent
       plugin:mapPlugin
       center : QtPositioning.coordinate(oldLat,oldLng);
       zoomLevel :7;
   }
function setCenter(lat,lng)
{
    mapView.pan(oldLat -lat,oldLng -lng)
    oldLat=lat
    oldLng=lng
}


}
