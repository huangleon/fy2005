inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
��˵�Ȳ��ϳ�������֣�������ҰС�������ﻹ�Ƿ������٣����Ƴ���Χ����
���岼����༯�У�����Ĵ��˼Ҿ������˵�����ɹ����ʵ��߲�ˮ����Զ����
���Ŀ���Ҳ��������ЪһЪ�š�
LONG
    );
    set("exits", ([ 
	"north" : AREA_FY"sgate",
	"east"  : __DIR__"sroad4",
	"west"  : __DIR__"sroad3",
	"south"  : __DIR__"fysroad1",
	//   "south" : AREA_FY"sroad1",

      ]));
    set("objects", ([
	__DIR__"npc/xiaofan" : 1,
	"/d/fy/npc/wind_soldier" : 1,
      ]) );        
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-320);
    set("coor/z",0);

    setup();
}
