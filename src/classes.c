/*****************************************************************************/
/*  LibreDWG - free implementation of the DWG file format                    */
/*                                                                           */
/*  Copyright (C) 2020 Free Software Foundation, Inc.                        */
/*                                                                           */
/*  This library is free software, licensed under the terms of the GNU       */
/*  General Public License as published by the Free Software Foundation,     */
/*  either version 3 of the License, or (at your option) any later version.  */
/*  You should have received a copy of the GNU General Public License        */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.    */
/*****************************************************************************/

/*
 * classes.c: map type to name. classify into unstable, debugging and unhandled.
 * written by Reini Urban
 */

#include "config.h"
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "classes.h"
#include "dynapi.h"

static const Dwg_Object_Type _classes_unstable[] =
  {
   DWG_TYPE_ACSH_BREP_CLASS,
   DWG_TYPE_ACSH_CHAMFER_CLASS,
   DWG_TYPE_ACSH_PYRAMID_CLASS,
   DWG_TYPE_ARC_DIMENSION,
   DWG_TYPE_ASSOCACTION,
   DWG_TYPE_ASSOCNETWORK,
   DWG_TYPE_ASSOCDEPENDENCY,
   DWG_TYPE_ASSOCGEOMDEPENDENCY,
   DWG_TYPE_ASSOCVALUEDEPENDENCY,
   DWG_TYPE_ASSOCBLENDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCEXTENDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCEXTRUDEDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCFILLETSURFACEACTIONBODY,
   DWG_TYPE_ASSOCLOFTEDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCNETWORKSURFACEACTIONBODY,
   DWG_TYPE_ASSOCPATCHSURFACEACTIONBODY,
   DWG_TYPE_ASSOCPLANESURFACEACTIONBODY,
   DWG_TYPE_ASSOCREVOLVEDSURFACEACTIONBODY,
   DWG_TYPE_BACKGROUND,
   DWG_TYPE_BLOCKALIGNMENTGRIP,
   DWG_TYPE_BLOCKALIGNMENTPARAMETER,
   DWG_TYPE_BLOCKLINEARPARAMETER,
   DWG_TYPE_BLOCKLOOKUPGRIP,
   DWG_TYPE_BLOCKROTATIONGRIP,
   DWG_TYPE_BLOCKROTATIONPARAMETER,
   DWG_TYPE_BLOCKVISIBILITYPARAMETER,
   DWG_TYPE_BLOCKXYPARAMETER,
   DWG_TYPE_DBCOLOR,
   DWG_TYPE_EVALUATION_GRAPH,
   DWG_TYPE_HELIX,
   DWG_TYPE_LARGE_RADIAL_DIMENSION,
   DWG_TYPE_LIGHTLIST,
   DWG_TYPE_MATERIAL,
   DWG_TYPE_MENTALRAYRENDERSETTINGS,
   DWG_TYPE_OBJECT_PTR,
   DWG_TYPE_PROXY_OBJECT,
   DWG_TYPE_RAPIDRTRENDERSETTINGS,
   DWG_TYPE_RENDERSETTINGS,
   DWG_TYPE_SECTION_SETTINGS,
   DWG_TYPE_SPATIAL_INDEX,
   DWG_TYPE_SUN,
   DWG_TYPE_TABLESTYLE,
   DWG_TYPE_WIPEOUT,
  };
static const Dwg_Object_Type _classes_debugging[] =
  {
   DWG_TYPE_ACMECOMMANDHISTORY,
   DWG_TYPE_ACMESCOPE,
   DWG_TYPE_ACMESTATEMGR,
   DWG_TYPE_ACSH_EXTRUSION_CLASS,
   DWG_TYPE_ACSH_LOFT_CLASS,
   DWG_TYPE_ACSH_REVOLVE_CLASS,
   DWG_TYPE_ACSH_SWEEP_CLASS,
   DWG_TYPE_ALDIMOBJECTCONTEXTDATA,
   DWG_TYPE_ANGDIMOBJECTCONTEXTDATA,
   DWG_TYPE_ANNOTSCALEOBJECTCONTEXTDATA,
   DWG_TYPE_ASSOC2DCONSTRAINTGROUP,
   DWG_TYPE_ASSOCRESTOREENTITYSTATEACTIONBODY,
   DWG_TYPE_ASSOCMLEADERACTIONBODY,
   DWG_TYPE_ASSOC3POINTANGULARDIMACTIONBODY,
   DWG_TYPE_ASSOCALIGNEDDIMACTIONBODY,
   DWG_TYPE_ASSOCORDINATEDIMACTIONBODY,
   DWG_TYPE_ASSOCROTATEDDIMACTIONBODY,
   DWG_TYPE_ASSOCSWEPTSURFACEACTIONBODY,
   DWG_TYPE_ASSOCDIMDEPENDENCYBODY,
   DWG_TYPE_ASSOCPERSSUBENTMANAGER,
   DWG_TYPE_ASSOCVARIABLE,
   DWG_TYPE_ASSOCOSNAPPOINTREFACTIONPARAM,
   DWG_TYPE_ASSOCASMBODYACTIONPARAM,
   DWG_TYPE_ASSOCACTIONPARAM,
   DWG_TYPE_ASSOCCOMPOUNDACTIONPARAM,
   DWG_TYPE_ASSOCEDGEACTIONPARAM,
   DWG_TYPE_ASSOCFACEACTIONPARAM,
   DWG_TYPE_ASSOCOBJECTACTIONPARAM,
   DWG_TYPE_ASSOCPATHACTIONPARAM,
   DWG_TYPE_ASSOCPOINTREFACTIONPARAM,
   DWG_TYPE_ASSOCVERTEXACTIONPARAM,
   DWG_TYPE_ASSOCARRAYMODIFYPARAMETERS,
   DWG_TYPE_ASSOCARRAYPATHPARAMETERS,
   DWG_TYPE_ASSOCARRAYPOLARPARAMETERS,
   DWG_TYPE_ASSOCARRAYRECTANGULARPARAMETERS,
   DWG_TYPE_ARCALIGNEDTEXT,
   DWG_TYPE_BLKREFOBJECTCONTEXTDATA,
   DWG_TYPE_ASSOCDIMDEPENDENCYBODY,
   DWG_TYPE_BLOCKPARAMDEPENDENCYBODY,
   DWG_TYPE_CONTEXTDATAMANAGER,
   DWG_TYPE_CSACDOCUMENTOPTIONS,
   DWG_TYPE_CURVEPATH,
   DWG_TYPE_DATALINK,
   DWG_TYPE_DATATABLE,
   DWG_TYPE_DMDIMOBJECTCONTEXTDATA,
   DWG_TYPE_DIMASSOC,
   DWG_TYPE_EXTRUDEDSURFACE,
   DWG_TYPE_FCFOBJECTCONTEXTDATA,
   DWG_TYPE_GEOMAPIMAGE,
   DWG_TYPE_GEOPOSITIONMARKER,
   DWG_TYPE_LAYOUTPRINTCONFIG,
   DWG_TYPE_LEADEROBJECTCONTEXTDATA,
   DWG_TYPE_LOFTEDSURFACE,
   DWG_TYPE_MLEADEROBJECTCONTEXTDATA,
   DWG_TYPE_MOTIONPATH,
   DWG_TYPE_MPOLYGON,
   DWG_TYPE_MTEXTATTRIBUTEOBJECTCONTEXTDATA,
   DWG_TYPE_MTEXTOBJECTCONTEXTDATA,
   DWG_TYPE_NAVISWORKSMODEL,
   DWG_TYPE_NAVISWORKSMODELDEF,
   DWG_TYPE_NURBSURFACE,
   DWG_TYPE_ORDDIMOBJECTCONTEXTDATA,
   DWG_TYPE_PERSUBENTMGR,
   DWG_TYPE_PLANESURFACE,
   DWG_TYPE_POINTPATH,
   DWG_TYPE_RADIMOBJECTCONTEXTDATA,
   DWG_TYPE_RADIMLGOBJECTCONTEXTDATA,
   DWG_TYPE_RENDERENTRY,
   DWG_TYPE_RENDERENVIRONMENT,
   DWG_TYPE_RENDERGLOBAL,
   DWG_TYPE_REVOLVEDSURFACE,
   DWG_TYPE_RTEXT,
   DWG_TYPE_SUNSTUDY,
   DWG_TYPE_SWEPTSURFACE,
   DWG_TYPE_TABLE,
   DWG_TYPE_TABLECONTENT,
   DWG_TYPE_TEXTOBJECTCONTEXTDATA,
   DWG_TYPE_TVDEVICEPROPERTIES,
   DWG_TYPE_VISIBILITYGRIPENTITY,
   DWG_TYPE_ALIGNMENTPARAMETERENTITY,
   DWG_TYPE_BASEPOINTPARAMETERENTITY,
   DWG_TYPE_FLIPPARAMETERENTITY,
   DWG_TYPE_LINEARPARAMETERENTITY,
   DWG_TYPE_POINTPARAMETERENTITY,
   DWG_TYPE_ROTATIONPARAMETERENTITY,
   DWG_TYPE_VISIBILITYPARAMETERENTITY,
   DWG_TYPE_XYPARAMETERENTITY,
   DWG_TYPE_BLOCKALIGNEDCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKANGULARCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKARRAYACTION,
   DWG_TYPE_BLOCKDIAMETRICCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKHORIZONTALCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKLINEARCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKLOOKUPACTION,
   DWG_TYPE_BLOCKLOOKUPPARAMETER,
   DWG_TYPE_BLOCKPOINTPARAMETER,
   DWG_TYPE_BLOCKPOLARGRIP,
   DWG_TYPE_BLOCKPOLARPARAMETER,
   DWG_TYPE_BLOCKPOLARSTRETCHACTION,
   DWG_TYPE_BLOCKPROPERTIESTABLE,
   DWG_TYPE_BLOCKPROPERTIESTABLEGRIP,
   DWG_TYPE_BLOCKRADIALCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKREPRESENTATION,
   DWG_TYPE_BLOCKSTRETCHACTION,
   DWG_TYPE_BLOCKUSERPARAMETER,
   DWG_TYPE_BLOCKVERTICALCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKXYGRIP,
   DWG_TYPE_DYNAMICBLOCKPROXYNODE,
   DWG_TYPE_POINTCLOUD,
   DWG_TYPE_POINTCLOUDEX,
   DWG_TYPE_POINTCLOUDDEF,
   DWG_TYPE_POINTCLOUDDEFEX,
   DWG_TYPE_POINTCLOUDDEF_REACTOR,
   DWG_TYPE_POINTCLOUDDEF_REACTOR_EX,
   DWG_TYPE_POINTCLOUDCOLORMAP,
  };
static const Dwg_Object_Type _classes_unhandled[] =
  {
   DWG_TYPE_ACDSRECORD,
   DWG_TYPE_ACDSSCHEMA,
   DWG_TYPE_NPOCOLLECTION,
   DWG_TYPE_RAPIDRTRENDERENVIRONMENT,
   DWG_TYPE_XREFPANELOBJECT,
  };

struct _obj_type_name {
  const Dwg_Object_Type type;
  const char *name;
};

static const struct _obj_type_name _dwg_type_name[] =
  {
   { DWG_TYPE_UNUSED, "UNUSED" },
   { DWG_TYPE_TEXT, "TEXT" },
   { DWG_TYPE_ATTRIB, "ATTRIB" }, // 0x02
   { DWG_TYPE_ATTDEF, "ATTDEF" }, // 0x03
   { DWG_TYPE_BLOCK, "BLOCK" }, // 0x04
   { DWG_TYPE_ENDBLK, "ENDBLK" }, // 0x05
   { DWG_TYPE_SEQEND, "SEQEND" }, // 0x06
   { DWG_TYPE_INSERT, "INSERT" }, // 0x07
   { DWG_TYPE_MINSERT, "MINSERT" }, // 0x08
   /* DWG_TYPE_<UNKNOWN> = 0x09, */
   { DWG_TYPE_VERTEX_2D, "VERTEX_2D" }, // 0x0a
   { DWG_TYPE_VERTEX_3D, "VERTEX_3D" }, // 0x0b
   { DWG_TYPE_VERTEX_MESH, "VERTEX_MESH" }, // 0x0c
   { DWG_TYPE_VERTEX_PFACE, "VERTEX_PFACE" }, // 0x0d
   { DWG_TYPE_VERTEX_PFACE_FACE, "VERTEX_PFACE_FACE" }, // 0x0e
   { DWG_TYPE_POLYLINE_2D, "POLYLINE_2D" }, // 0x0f
   { DWG_TYPE_POLYLINE_3D, "POLYLINE_3D" }, // 0x10
   { DWG_TYPE_ARC, "ARC" }, // 0x11
   { DWG_TYPE_CIRCLE, "CIRCLE" }, // 0x12
   { DWG_TYPE_LINE, "LINE" }, // 0x13
   { DWG_TYPE_DIMENSION_ORDINATE, "DIMENSION_ORDINATE" }, // 0x14
   { DWG_TYPE_DIMENSION_LINEAR, "DIMENSION_LINEAR" }, // 0x15
   { DWG_TYPE_DIMENSION_ALIGNED, "DIMENSION_ALIGNED" }, // 0x16
   { DWG_TYPE_DIMENSION_ANG3PT, "DIMENSION_ANG3PT" }, // 0x17
   { DWG_TYPE_DIMENSION_ANG2LN, "DIMENSION_ANG2LN" }, // 0x18
   { DWG_TYPE_DIMENSION_RADIUS, "DIMENSION_RADIUS" }, // 0x19
   { DWG_TYPE_DIMENSION_DIAMETER, "DIMENSION_DIAMETER" }, // 0x1A
   { DWG_TYPE_POINT, "POINT" }, // 0x1b
   { DWG_TYPE__3DFACE, "_3DFACE" }, // 0x1c
   { DWG_TYPE_POLYLINE_PFACE, "POLYLINE_PFACE" }, // 0x1d
   { DWG_TYPE_POLYLINE_MESH, "POLYLINE_MESH" }, // 0x1e
   { DWG_TYPE_SOLID, "SOLID" }, // 0x1f
   { DWG_TYPE_TRACE, "TRACE" }, // 0x20
   { DWG_TYPE_SHAPE, "SHAPE" }, // 0x21
   { DWG_TYPE_VIEWPORT, "VIEWPORT" }, // 0x22
   { DWG_TYPE_ELLIPSE, "ELLIPSE" }, // 0x23
   { DWG_TYPE_SPLINE, "SPLINE" }, // 0x24
   { DWG_TYPE_REGION, "REGION" }, // 0x25
   { DWG_TYPE__3DSOLID, "_3DSOLID" }, // 0x26
   { DWG_TYPE_BODY, "BODY" }, // 0x27
   { DWG_TYPE_RAY, "RAY" }, // 0x28
   { DWG_TYPE_XLINE, "XLINE" }, // 0x29
   { DWG_TYPE_DICTIONARY, "DICTIONARY" }, // 0x2a
   { DWG_TYPE_OLEFRAME, "OLEFRAME" }, // 0x2b
   { DWG_TYPE_MTEXT, "MTEXT" }, // 0x2c
   { DWG_TYPE_LEADER, "LEADER" }, // 0x2d
   { DWG_TYPE_TOLERANCE, "TOLERANCE" }, // 0x2e
   { DWG_TYPE_MLINE, "MLINE" }, // 0x2f
   { DWG_TYPE_BLOCK_CONTROL, "BLOCK_CONTROL" }, // 0x30
   { DWG_TYPE_BLOCK_HEADER, "BLOCK_HEADER" }, // 0x31
   { DWG_TYPE_LAYER_CONTROL, "LAYER_CONTROL" }, // 0x32
   { DWG_TYPE_LAYER, "LAYER" }, // 0x33
   { DWG_TYPE_STYLE_CONTROL, "STYLE_CONTROL" }, // 0x34
   { DWG_TYPE_STYLE, "STYLE" }, // 0x35
   /* DWG_TYPE_<UNKNOWN> = 0x36, */
   /* DWG_TYPE_<UNKNOWN> = 0x37, */
   { DWG_TYPE_LTYPE_CONTROL, "LTYPE_CONTROL" }, // 0x38
   { DWG_TYPE_LTYPE, "LTYPE" }, // 0x39
   /* DWG_TYPE_<UNKNOWN> = 0x3a, */
   /* DWG_TYPE_<UNKNOWN> = 0x3b, */
   { DWG_TYPE_VIEW_CONTROL, "VIEW_CONTROL" }, // 0x3c
   { DWG_TYPE_VIEW, "VIEW" }, // 0x3d
   { DWG_TYPE_UCS_CONTROL, "UCS_CONTROL" }, // 0x3e
   { DWG_TYPE_UCS, "UCS" }, // 0x3f
   { DWG_TYPE_VPORT_CONTROL, "VPORT_CONTROL" }, // 0x40
   { DWG_TYPE_VPORT, "VPORT" }, // 0x41
   { DWG_TYPE_APPID_CONTROL, "APPID_CONTROL" }, // 0x42
   { DWG_TYPE_APPID, "APPID" }, // 0x43
   { DWG_TYPE_DIMSTYLE_CONTROL, "DIMSTYLE_CONTROL" }, // 0x44
   { DWG_TYPE_DIMSTYLE, "DIMSTYLE" }, // 0x45
   { DWG_TYPE_VX_CONTROL, "VX_CONTROL" }, // 0x46
   { DWG_TYPE_VX_TABLE_RECORD, "VX_TABLE_RECORD" }, // 0x47
   { DWG_TYPE_GROUP, "GROUP" }, // 0x48
   { DWG_TYPE_MLINESTYLE, "MLINESTYLE" }, // 0x49
   { DWG_TYPE_OLE2FRAME, "OLE2FRAME" }, // 0x4a
   { DWG_TYPE_DUMMY, "DUMMY" }, // 0x4b
   { DWG_TYPE_LONG_TRANSACTION, "LONG_TRANSACTION" }, // 0x4c
   { DWG_TYPE_LWPOLYLINE, "LWPOLYLINE" }, // 0x4d /* ?? */
   { DWG_TYPE_HATCH, "HATCH" }, // 0x4e
   { DWG_TYPE_XRECORD, "XRECORD" }, // 0x4f
   { DWG_TYPE_PLACEHOLDER, "PLACEHOLDER" }, // 0x50
   { DWG_TYPE_VBA_PROJECT, "VBA_PROJECT" }, // 0x51
   { DWG_TYPE_LAYOUT, "LAYOUT" }, // 0x52
   { DWG_TYPE_PROXY_ENTITY, "PROXY_ENTITY" }, // 0x1f2 498
   { DWG_TYPE_PROXY_OBJECT, "PROXY_OBJECT" }, // 0x1f3 499
   /* non-fixed types > 500. not stored as type, but as fixedtype */
   { DWG_TYPE_ACDSRECORD, "ACDSRECORD" }, // 0x1ff + 1
   { DWG_TYPE_ACDSSCHEMA, "ACDSSCHEMA" },
   { DWG_TYPE_ACMECOMMANDHISTORY, "ACMECOMMANDHISTORY" },
   { DWG_TYPE_ACMESCOPE, "ACMESCOPE" },
   { DWG_TYPE_ACMESTATEMGR, "ACMESTATEMGR" },
   { DWG_TYPE_ACSH_BOOLEAN_CLASS, "ACSH_BOOLEAN_CLASS" },
   { DWG_TYPE_ACSH_BOX_CLASS, "ACSH_BOX_CLASS" },
   { DWG_TYPE_ACSH_BREP_CLASS, "ACSH_BREP_CLASS" },
   { DWG_TYPE_ACSH_CHAMFER_CLASS, "ACSH_CHAMFER_CLASS" },
   { DWG_TYPE_ACSH_CONE_CLASS, "ACSH_CONE_CLASS" },
   { DWG_TYPE_ACSH_CYLINDER_CLASS, "ACSH_CYLINDER_CLASS" },
   { DWG_TYPE_ACSH_EXTRUSION_CLASS, "ACSH_EXTRUSION_CLASS" },
   { DWG_TYPE_ACSH_FILLET_CLASS, "ACSH_FILLET_CLASS" },
   { DWG_TYPE_ACSH_HISTORY_CLASS, "ACSH_HISTORY_CLASS" },
   { DWG_TYPE_ACSH_LOFT_CLASS, "ACSH_LOFT_CLASS" },
   { DWG_TYPE_ACSH_PYRAMID_CLASS, "ACSH_PYRAMID_CLASS" },
   { DWG_TYPE_ACSH_REVOLVE_CLASS, "ACSH_REVOLVE_CLASS" },
   { DWG_TYPE_ACSH_SPHERE_CLASS, "ACSH_SPHERE_CLASS" },
   { DWG_TYPE_ACSH_SWEEP_CLASS, "ACSH_SWEEP_CLASS" },
   { DWG_TYPE_ACSH_TORUS_CLASS, "ACSH_TORUS_CLASS" },
   { DWG_TYPE_ACSH_WEDGE_CLASS, "ACSH_WEDGE_CLASS" },
   { DWG_TYPE_ALDIMOBJECTCONTEXTDATA, "ALDIMOBJECTCONTEXTDATA" },
   { DWG_TYPE_ALIGNMENTPARAMETERENTITY, "ALIGNMENTPARAMETERENTITY" },
   { DWG_TYPE_ANGDIMOBJECTCONTEXTDATA, "ANGDIMOBJECTCONTEXTDATA" },
   { DWG_TYPE_ANNOTSCALEOBJECTCONTEXTDATA, "ANNOTSCALEOBJECTCONTEXTDATA" },
   { DWG_TYPE_ARC_DIMENSION, "ARC_DIMENSION" },
   { DWG_TYPE_ASSOC2DCONSTRAINTGROUP, "ASSOC2DCONSTRAINTGROUP" },
   { DWG_TYPE_ASSOC3POINTANGULARDIMACTIONBODY, "ASSOC3POINTANGULARDIMACTIONBODY" },
   { DWG_TYPE_ASSOCACTION, "ASSOCACTION" },
   { DWG_TYPE_ASSOCACTIONPARAM, "ASSOCACTIONPARAM" },
   { DWG_TYPE_ASSOCALIGNEDDIMACTIONBODY, "ASSOCALIGNEDDIMACTIONBODY" },
   { DWG_TYPE_ASSOCARRAYMODIFYPARAMETERS, "ASSOCARRAYMODIFYPARAMETERS" },
   { DWG_TYPE_ASSOCARRAYPATHPARAMETERS, "ASSOCARRAYPATHPARAMETERS" },
   { DWG_TYPE_ASSOCARRAYPOLARPARAMETERS, "ASSOCARRAYPOLARPARAMETERS" },
   { DWG_TYPE_ASSOCARRAYRECTANGULARPARAMETERS, "ASSOCARRAYRECTANGULARPARAMETERS" },
   { DWG_TYPE_ASSOCASMBODYACTIONPARAM, "ASSOCASMBODYACTIONPARAM" },
   { DWG_TYPE_ASSOCBLENDSURFACEACTIONBODY, "ASSOCBLENDSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCCOMPOUNDACTIONPARAM, "ASSOCCOMPOUNDACTIONPARAM" },
   { DWG_TYPE_ASSOCDEPENDENCY, "ASSOCDEPENDENCY" },
   { DWG_TYPE_ASSOCDIMDEPENDENCYBODY, "ASSOCDIMDEPENDENCYBODY" },
   { DWG_TYPE_ASSOCEDGEACTIONPARAM, "ASSOCEDGEACTIONPARAM" },
   { DWG_TYPE_ASSOCEXTENDSURFACEACTIONBODY, "ASSOCEXTENDSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCEXTRUDEDSURFACEACTIONBODY, "ASSOCEXTRUDEDSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCFACEACTIONPARAM, "ASSOCFACEACTIONPARAM" },
   { DWG_TYPE_ASSOCFILLETSURFACEACTIONBODY, "ASSOCFILLETSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCGEOMDEPENDENCY, "ASSOCGEOMDEPENDENCY" },
   { DWG_TYPE_ASSOCLOFTEDSURFACEACTIONBODY, "ASSOCLOFTEDSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCMLEADERACTIONBODY, "ASSOCMLEADERACTIONBODY" },
   { DWG_TYPE_ASSOCNETWORK, "ASSOCNETWORK" },
   { DWG_TYPE_ASSOCNETWORKSURFACEACTIONBODY, "ASSOCNETWORKSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCOBJECTACTIONPARAM, "ASSOCOBJECTACTIONPARAM" },
   { DWG_TYPE_ASSOCOFFSETSURFACEACTIONBODY, "ASSOCOFFSETSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCORDINATEDIMACTIONBODY, "ASSOCORDINATEDIMACTIONBODY" },
   { DWG_TYPE_ASSOCOSNAPPOINTREFACTIONPARAM, "ASSOCOSNAPPOINTREFACTIONPARAM" },
   { DWG_TYPE_ASSOCPATCHSURFACEACTIONBODY, "ASSOCPATCHSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCPATHACTIONPARAM, "ASSOCPATHACTIONPARAM" },
   { DWG_TYPE_ASSOCPERSSUBENTMANAGER, "ASSOCPERSSUBENTMANAGER" },
   { DWG_TYPE_ASSOCPLANESURFACEACTIONBODY, "ASSOCPLANESURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCPOINTREFACTIONPARAM, "ASSOCPOINTREFACTIONPARAM" },
   { DWG_TYPE_ASSOCRESTOREENTITYSTATEACTIONBODY, "ASSOCRESTOREENTITYSTATEACTIONBODY" },
   { DWG_TYPE_ASSOCREVOLVEDSURFACEACTIONBODY, "ASSOCREVOLVEDSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCROTATEDDIMACTIONBODY, "ASSOCROTATEDDIMACTIONBODY" },
   { DWG_TYPE_ASSOCSWEPTSURFACEACTIONBODY, "ASSOCSWEPTSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCTRIMSURFACEACTIONBODY, "ASSOCTRIMSURFACEACTIONBODY" },
   { DWG_TYPE_ASSOCVALUEDEPENDENCY, "ASSOCVALUEDEPENDENCY" },
   { DWG_TYPE_ASSOCVARIABLE, "ASSOCVARIABLE" },
   { DWG_TYPE_ASSOCVERTEXACTIONPARAM, "ASSOCVERTEXACTIONPARAM" },
   { DWG_TYPE_ARCALIGNEDTEXT, "ARCALIGNEDTEXT" },
   { DWG_TYPE_BACKGROUND, "BACKGROUND" },
   { DWG_TYPE_BASEPOINTPARAMETERENTITY, "BASEPOINTPARAMETERENTITY" },
   { DWG_TYPE_BLKREFOBJECTCONTEXTDATA, "BLKREFOBJECTCONTEXTDATA" },
   { DWG_TYPE_BLOCKALIGNEDCONSTRAINTPARAMETER, "BLOCKALIGNEDCONSTRAINTPARAMETER" },
   { DWG_TYPE_BLOCKALIGNMENTGRIP, "BLOCKALIGNMENTGRIP" },
   { DWG_TYPE_BLOCKALIGNMENTPARAMETER, "BLOCKALIGNMENTPARAMETER" },
   { DWG_TYPE_BLOCKANGULARCONSTRAINTPARAMETER, "BLOCKANGULARCONSTRAINTPARAMETER" },
   { DWG_TYPE_BLOCKARRAYACTION, "BLOCKARRAYACTION" },
   { DWG_TYPE_BLOCKBASEPOINTPARAMETER, "BLOCKBASEPOINTPARAMETER" },
   { DWG_TYPE_BLOCKDIAMETRICCONSTRAINTPARAMETER, "BLOCKDIAMETRICCONSTRAINTPARAMETER" },
   { DWG_TYPE_BLOCKFLIPACTION, "BLOCKFLIPACTION" },
   { DWG_TYPE_BLOCKFLIPGRIP, "BLOCKFLIPGRIP" },
   { DWG_TYPE_BLOCKFLIPPARAMETER, "BLOCKFLIPPARAMETER" },
   { DWG_TYPE_BLOCKGRIPLOCATIONCOMPONENT, "BLOCKGRIPLOCATIONCOMPONENT" },
   { DWG_TYPE_BLOCKHORIZONTALCONSTRAINTPARAMETER, "BLOCKHORIZONTALCONSTRAINTPARAMETER" },
   { DWG_TYPE_BLOCKLINEARCONSTRAINTPARAMETER, "BLOCKLINEARCONSTRAINTPARAMETER" },
   { DWG_TYPE_BLOCKLINEARGRIP, "BLOCKLINEARGRIP" },
   { DWG_TYPE_BLOCKLINEARPARAMETER, "BLOCKLINEARPARAMETER" },
   { DWG_TYPE_BLOCKLOOKUPACTION, "BLOCKLOOKUPACTION" },
   { DWG_TYPE_BLOCKLOOKUPGRIP, "BLOCKLOOKUPGRIP" },
   { DWG_TYPE_BLOCKLOOKUPPARAMETER, "BLOCKLOOKUPPARAMETER" },
   { DWG_TYPE_BLOCKMOVEACTION, "BLOCKMOVEACTION" },
   { DWG_TYPE_BLOCKPARAMDEPENDENCYBODY, "BLOCKPARAMDEPENDENCYBODY" },
   { DWG_TYPE_BLOCKPOINTPARAMETER, "BLOCKPOINTPARAMETER" },
   { DWG_TYPE_BLOCKPOLARGRIP, "BLOCKPOLARGRIP" },
   { DWG_TYPE_BLOCKPOLARPARAMETER, "BLOCKPOLARPARAMETER" },
   { DWG_TYPE_BLOCKPOLARSTRETCHACTION, "BLOCKPOLARSTRETCHACTION" },
   { DWG_TYPE_BLOCKPROPERTIESTABLE, "BLOCKPROPERTIESTABLE" },
   { DWG_TYPE_BLOCKPROPERTIESTABLEGRIP, "BLOCKPROPERTIESTABLEGRIP" },
   { DWG_TYPE_BLOCKRADIALCONSTRAINTPARAMETER, "BLOCKRADIALCONSTRAINTPARAMETER" },
   { DWG_TYPE_BLOCKREPRESENTATION, "BLOCKREPRESENTATION" },
   { DWG_TYPE_BLOCKROTATEACTION, "BLOCKROTATEACTION" },
   { DWG_TYPE_BLOCKROTATIONGRIP, "BLOCKROTATIONGRIP" },
   { DWG_TYPE_BLOCKROTATIONPARAMETER, "BLOCKROTATIONPARAMETER" },
   { DWG_TYPE_BLOCKSCALEACTION, "BLOCKSCALEACTION" },
   { DWG_TYPE_BLOCKSTRETCHACTION, "BLOCKSTRETCHACTION" },
   { DWG_TYPE_BLOCKUSERPARAMETER, "BLOCKUSERPARAMETER" },
   { DWG_TYPE_BLOCKVERTICALCONSTRAINTPARAMETER, "BLOCKVERTICALCONSTRAINTPARAMETER" },
   { DWG_TYPE_BLOCKVISIBILITYGRIP, "BLOCKVISIBILITYGRIP" },
   { DWG_TYPE_BLOCKVISIBILITYPARAMETER, "BLOCKVISIBILITYPARAMETER" },
   { DWG_TYPE_BLOCKXYGRIP, "BLOCKXYGRIP" },
   { DWG_TYPE_BLOCKXYPARAMETER, "BLOCKXYPARAMETER" },
   { DWG_TYPE_CAMERA, "CAMERA" },
   { DWG_TYPE_CELLSTYLEMAP, "CELLSTYLEMAP" },
   { DWG_TYPE_CONTEXTDATAMANAGER, "CONTEXTDATAMANAGER" },
   { DWG_TYPE_CSACDOCUMENTOPTIONS, "CSACDOCUMENTOPTIONS" },
   { DWG_TYPE_DATALINK, "DATALINK" },
   { DWG_TYPE_DATATABLE, "DATATABLE" },
   { DWG_TYPE_DBCOLOR, "DBCOLOR" },
   { DWG_TYPE_DETAILVIEWSTYLE, "DETAILVIEWSTYLE" },
   { DWG_TYPE_DICTIONARYVAR, "DICTIONARYVAR" },
   { DWG_TYPE_DICTIONARYWDFLT, "DICTIONARYWDFLT" },
   { DWG_TYPE_DIMASSOC, "DIMASSOC" },
   { DWG_TYPE_DMDIMOBJECTCONTEXTDATA, "DMDIMOBJECTCONTEXTDATA" },
   { DWG_TYPE_DYNAMICBLOCKPROXYNODE, "DYNAMICBLOCKPROXYNODE" },
   { DWG_TYPE_DYNAMICBLOCKPURGEPREVENTER, "DYNAMICBLOCKPURGEPREVENTER" },
   { DWG_TYPE_EVALUATION_GRAPH, "EVALUATION_GRAPH" },
   { DWG_TYPE_EXTRUDEDSURFACE, "EXTRUDEDSURFACE" },
   { DWG_TYPE_FCFOBJECTCONTEXTDATA, "FCFOBJECTCONTEXTDATA" },
   { DWG_TYPE_FIELD, "FIELD" },
   { DWG_TYPE_FIELDLIST, "FIELDLIST" },
   { DWG_TYPE_FLIPPARAMETERENTITY, "FLIPPARAMETERENTITY" },
   { DWG_TYPE_GEODATA, "GEODATA" },
   { DWG_TYPE_GEOMAPIMAGE, "GEOMAPIMAGE" },
   { DWG_TYPE_GEOPOSITIONMARKER, "GEOPOSITIONMARKER" },
   { DWG_TYPE_HELIX, "HELIX" },
   { DWG_TYPE_IDBUFFER, "IDBUFFER" },
   { DWG_TYPE_IMAGE, "IMAGE" },
   { DWG_TYPE_IMAGEDEF, "IMAGEDEF" },
   { DWG_TYPE_IMAGEDEF_REACTOR, "IMAGEDEF_REACTOR" },
   { DWG_TYPE_INDEX, "INDEX" },
   { DWG_TYPE_LARGE_RADIAL_DIMENSION, "LARGE_RADIAL_DIMENSION" },
   { DWG_TYPE_LAYERFILTER, "LAYERFILTER" },
   { DWG_TYPE_LAYER_INDEX, "LAYER_INDEX" },
   { DWG_TYPE_LAYOUTPRINTCONFIG, "LAYOUTPRINTCONFIG" },
   { DWG_TYPE_LEADEROBJECTCONTEXTDATA, "LEADEROBJECTCONTEXTDATA" },
   { DWG_TYPE_LIGHT, "LIGHT" },
   { DWG_TYPE_LIGHTLIST, "LIGHTLIST" },
   { DWG_TYPE_LINEARPARAMETERENTITY, "LINEARPARAMETERENTITY" },
   { DWG_TYPE_LOFTEDSURFACE, "LOFTEDSURFACE" },
   { DWG_TYPE_MATERIAL, "MATERIAL" },
   { DWG_TYPE_MENTALRAYRENDERSETTINGS, "MENTALRAYRENDERSETTINGS" },
   { DWG_TYPE_MESH, "MESH" },
   { DWG_TYPE_MLEADEROBJECTCONTEXTDATA, "MLEADEROBJECTCONTEXTDATA" },
   { DWG_TYPE_MLEADERSTYLE, "MLEADERSTYLE" },
   { DWG_TYPE_MOTIONPATH, "MOTIONPATH" },
   { DWG_TYPE_MPOLYGON, "MPOLYGON" },
   { DWG_TYPE_MTEXTATTRIBUTEOBJECTCONTEXTDATA, "MTEXTATTRIBUTEOBJECTCONTEXTDATA" },
   { DWG_TYPE_MTEXTOBJECTCONTEXTDATA, "MTEXTOBJECTCONTEXTDATA" },
   { DWG_TYPE_MULTILEADER, "MULTILEADER" },
   { DWG_TYPE_NAVISWORKSMODEL, "NAVISWORKSMODEL" },
   { DWG_TYPE_NAVISWORKSMODELDEF, "NAVISWORKSMODELDEF" },
   { DWG_TYPE_NPOCOLLECTION, "NPOCOLLECTION" },
   { DWG_TYPE_OBJECT_PTR, "OBJECT_PTR" },
   { DWG_TYPE_ORDDIMOBJECTCONTEXTDATA, "ORDDIMOBJECTCONTEXTDATA" },
   { DWG_TYPE_PERSUBENTMGR, "PERSUBENTMGR" },
   { DWG_TYPE_PLANESURFACE, "PLANESURFACE" },
   { DWG_TYPE_PLOTSETTINGS, "PLOTSETTINGS" },
   { DWG_TYPE_POINTCLOUD, "POINTCLOUD" },
   { DWG_TYPE_POINTCLOUDEX, "POINTCLOUDEX" },
   { DWG_TYPE_POINTCLOUDDEF, "POINTCLOUDDEF" },
   { DWG_TYPE_POINTCLOUDDEFEX, "POINTCLOUDDEFEX" },
   { DWG_TYPE_POINTCLOUDDEF_REACTOR, "POINTCLOUDDEF_REACTOR" },
   { DWG_TYPE_POINTCLOUDDEF_REACTOR_EX, "POINTCLOUDDEF_REACTOR_EX" },
   { DWG_TYPE_POINTCLOUDCOLORMAP, "POINTCLOUDCOLORMAP" },
   { DWG_TYPE_POINTPARAMETERENTITY, "POINTPARAMETERENTITY" },
   { DWG_TYPE_POINTPATH, "POINTPATH" },
   { DWG_TYPE_RADIMLGOBJECTCONTEXTDATA, "RADIMLGOBJECTCONTEXTDATA" },
   { DWG_TYPE_RADIMOBJECTCONTEXTDATA, "RADIMOBJECTCONTEXTDATA" },
   { DWG_TYPE_RAPIDRTRENDERENVIRONMENT, "RAPIDRTRENDERENVIRONMENT" },
   { DWG_TYPE_RAPIDRTRENDERSETTINGS, "RAPIDRTRENDERSETTINGS" },
   { DWG_TYPE_RASTERVARIABLES, "RASTERVARIABLES" },
   { DWG_TYPE_RENDERENTRY, "RENDERENTRY" },
   { DWG_TYPE_RENDERENVIRONMENT, "RENDERENVIRONMENT" },
   { DWG_TYPE_RENDERGLOBAL, "RENDERGLOBAL" },
   { DWG_TYPE_REVOLVEDSURFACE, "REVOLVEDSURFACE" },
   { DWG_TYPE_ROTATIONPARAMETERENTITY, "ROTATIONPARAMETERENTITY" },
   { DWG_TYPE_RTEXT, "RTEXT" },
   { DWG_TYPE_SCALE, "SCALE" },
   { DWG_TYPE_SECTIONOBJECT, "SECTIONOBJECT" },
   { DWG_TYPE_SECTIONVIEWSTYLE, "SECTIONVIEWSTYLE" },
   { DWG_TYPE_SECTION_MANAGER, "SECTION_MANAGER" },
   { DWG_TYPE_SECTION_SETTINGS, "SECTION_SETTINGS" },
   { DWG_TYPE_SORTENTSTABLE, "SORTENTSTABLE" },
   { DWG_TYPE_SPATIAL_FILTER, "SPATIAL_FILTER" },
   { DWG_TYPE_SPATIAL_INDEX, "SPATIAL_INDEX" },
   { DWG_TYPE_SUN, "SUN" },
   { DWG_TYPE_SUNSTUDY, "SUNSTUDY" },
   { DWG_TYPE_SWEPTSURFACE, "SWEPTSURFACE" },
   { DWG_TYPE_TABLE, "TABLE" },
   { DWG_TYPE_TABLECONTENT, "TABLECONTENT" },
   { DWG_TYPE_TABLEGEOMETRY, "TABLEGEOMETRY" },
   { DWG_TYPE_TABLESTYLE, "TABLESTYLE" },
   { DWG_TYPE_TEXTOBJECTCONTEXTDATA, "TEXTOBJECTCONTEXTDATA" },
   { DWG_TYPE_TVDEVICEPROPERTIES, "TVDEVICEPROPERTIES" }, /* not in DXF */
   { DWG_TYPE_UNDERLAY, "UNDERLAY" }, /* not separate DGN,DWF,PDF types */
   { DWG_TYPE_UNDERLAYDEFINITION, "UNDERLAYDEFINITION" }, /* not separate DGN,DWF,PDF types */
   { DWG_TYPE_VISIBILITYGRIPENTITY, "VISIBILITYGRIPENTITY" },
   { DWG_TYPE_VISIBILITYPARAMETERENTITY, "VISIBILITYPARAMETERENTITY" },
   { DWG_TYPE_VISUALSTYLE, "VISUALSTYLE" },
   { DWG_TYPE_WIPEOUT, "WIPEOUT" },
   { DWG_TYPE_WIPEOUTVARIABLES, "WIPEOUTVARIABLES" },
   { DWG_TYPE_XREFPANELOBJECT, "XREFPANELOBJECT" },
   { DWG_TYPE_XYPARAMETERENTITY, "XYPARAMETERENTITY" },

   // after 1.0 add new types here for binary compat

   { DWG_TYPE_FREED      , "FREED      " }, // 0xfffd
   { DWG_TYPE_UNKNOWN_ENT, "UNKNOWN_ENT" }, // 0xfffe
   { DWG_TYPE_UNKNOWN_OBJ, "UNKNOWN_OBJ" }, // 0xffff
  };

const char *dwg_type_name (const Dwg_Object_Type type)
{
  const struct _obj_type_name *s = (struct _obj_type_name *)_dwg_type_name;
  // linear, TODO better binary search. Or a switch jumptable, as in free.
  // just 12 unhandled are missing in objects.inc
  for (; s->type != DWG_TYPE_UNKNOWN_OBJ; s++)
    {
      if (type == s->type)
        return s->name;
    }
  return NULL;
}

// TODO: gperf would be preferred here. with name -> type, dxfname, stability, ...
Dwg_Object_Type dwg_name_type (const char *name)
{
  struct _obj_type_name *s = (struct _obj_type_name *)_dwg_type_name;
  for (; s->type != DWG_TYPE_UNKNOWN_OBJ; s++)
    {
      if (strEQ (name, s->name))
        return s->type;
    }
  return DWG_TYPE_UNUSED;
}

bool
is_type_stable (const Dwg_Object_Type type)
{
  // clang-format off
  return !is_type_unstable (type)
      && !is_type_debugging (type)
      && !is_type_unstable (type)
      && type != DWG_TYPE_UNKNOWN_OBJ
      && type != DWG_TYPE_UNKNOWN_ENT
      && type != DWG_TYPE_FREED;
  // clang-format on
}

bool
is_type_unstable_all (const Dwg_Object_Type type)
{
  return is_type_unstable (type)
      || is_type_debugging (type);
}

bool is_type_unstable (const Dwg_Object_Type type)
{
  // unsorted, only linear
  for (int i = 0; i < ARRAY_SIZE(_classes_unstable); i++)
    {
      if (type == _classes_unstable[i])
        return true;
    }
  return false;
}
bool is_type_debugging (const Dwg_Object_Type type)
{
  // unsorted, only linear
  for (int i = 0; i < ARRAY_SIZE(_classes_debugging); i++)
    {
      if (type == _classes_debugging[i])
        return true;
    }
  return false;
}
bool is_type_unhandled (const Dwg_Object_Type type)
{
  // unsorted, only linear
  for (int i = 0; i < ARRAY_SIZE(_classes_unhandled); i++)
    {
      if (type == _classes_unhandled[i])
        return true;
    }
  return false;
}

bool is_class_stable (const char* name)
{
  return is_type_stable (dwg_name_type (name));
}
bool is_class_unstable (const char* name)
{
  return is_type_unstable (dwg_name_type (name));
}
bool is_class_debugging (const char* name)
{
  return is_type_debugging (dwg_name_type (name));
}
bool is_class_unhandled (const char* name)
{
  return is_type_unhandled (dwg_name_type (name));
}

bool dwg_find_class (const Dwg_Data *restrict dwg, const char* dxfname, BITCODE_BS *numberp)
{
  // linear search is good enough, with ~20 classes
  for (BITCODE_BS i = 0; i < dwg->num_classes; i++)
    {
      // ->dxfname is always ASCII/UTF-8, dxfname_u is the TU counterpart
      if (strEQ (dwg->dwg_class[i].dxfname, dxfname))
        {
          if (numberp)
            *numberp = dwg->dwg_class[i].number;
          return true;
        }
    }
  return false;
}

void
object_alias (char *restrict name)
{
  const int len = strlen (name);
  // check aliases (dxfname => name)
  if (len == strlen ("PDFDEFINITION") && strEQc (&name[3], "DEFINITION"))
    strcpy (name, "UNDERLAYDEFINITION");
  else if (strEQc (name, "ACAD_PROXY_OBJECT"))
    strcpy (name, "PROXY_OBJECT");
  else if (strEQc (name, "ACDBPERSSUBENTMANAGER"))
    strcpy (name, "PERSUBENTMGR");
  else if (strEQc (name, "ACDB_DYNAMICBLOCKPURGEPREVENTER_VERSION"))
    strcpy (name, "DYNAMICBLOCKPURGEPREVENTER");
  else if (strEQc (name, "EXACXREFPANELOBJECT"))
    strcpy (name, "XREFPANELOBJECT");
  else if (strstr (name, "_BACKGROUND"))
    strcpy (name, "BACKGROUND");
  // ACDB_*OBJECTCONTEXTDATA_CLASS => *OBJECTCONTEXTDATA
  else if (memBEGINc (name, "ACAD_") && len > 28 && strEQc (&name[len-6], "_CLASS"))
    {
      name[len-6] = '\0';
      if (is_dwg_object (&name[5]))
        memmove (name, &name[5], len - 4);
      else
        name[len-6] = '_';
    }
  // strip ACAD_ prefix
  else if (memBEGINc (name, "ACAD_") && is_dwg_object (&name[5]))
    memmove (name, &name[5], len - 4);
  // strip the ACDB prefix
  else if (memBEGINc (name, "ACDB") && is_dwg_object (&name[4]))
    memmove (name, &name[4], len - 3);
}

void
entity_alias (char *restrict name)
{
  const int len = strlen (name);
  // check aliases (dxfname => name)
  if (strEQc (name, "ACAD_TABLE"))
    strcpy (name, "TABLE");
  else if (strEQc (name, "ACAD_PROXY_ENTITY"))
    strcpy (name, "PROXY_ENTITY");
  /* else if (strEQc (name, "ACAD_PROXY_ENTITY_WRAPPER"))
    strcpy (name, "PROXY_ENTITY_WRAPPER"); */
  else if (strEQc (name, "ACDBPLACEHOLDER"))
    strcpy (name, "PLACEHOLDER");
  else if (strEQc (name, "POLYLINE"))
    strcpy (name, "POLYLINE_2D"); // other POLYLINE_* by flag or subclass?
  else if (strEQc (name, "VERTEX"))
    strcpy (name, "VERTEX_2D"); // other VERTEX_* by flag?
  else if (len == strlen ("PDFUNDERLAY") && strEQc (&name[3], "UNDERLAY"))
    strcpy (name, "UNDERLAY");
  else if (strEQc (name, "SURFACE"))
    strcpy (name, "PLANESURFACE");
  else if (strEQc (name, "COORDINATION_MODEL")) //??
    strcpy (name, "NAVISWORKSMODEL");
  else if (strEQc (name, "POSITIONMARKER"))
    strcpy (name, "GEOPOSITIONMARKER");
  // if (strEQc (name, "BLOCK"))
  //  strcpy (name, "BLOCK_HEADER");
  // else if (strEQc (name, "VERTEX_MESH") || strEQc (name, "VERTEX_PFACE"))
  //  strcpy (name, "VERTEX_3D");
  // else if (strEQc (name, "DIMENSION"))
  //  strcpy (name, "DIMENSION_ANG2LN");   // allocate room for the largest
  // strip a ACAD_ prefix
  else if (memBEGINc (name, "ACAD_") && is_dwg_entity (&name[5]))
    memmove (name, &name[5], len - 4);
  // strip the ACDB prefix
  else if (memBEGINc (name, "ACDB") && is_dwg_entity (&name[4]))
    memmove (name, &name[4], len - 3);
}
