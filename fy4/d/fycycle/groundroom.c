#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
��ʯ��֮�£������ڵص�ȴ������أ�һ����������þ���һ����ȥ��ֻ����
���澫�ɣ��������������ﰴ�硢ѩ���ס��硢�ǡ�ˮ���ꡢ�������˼䷿�ݡ���
����Ȼ�������˹����˹���Ȼ���ɣ����칤֮���ȴ������
LONG
        );
  	set("objects", ([
       ]) );
       
	set("exits/water",__DIR__"swordroom");
	set("exits/snow",__DIR__"bladeroom");
	set("exits/rain",__DIR__"staffroom");
	set("exits/lightning",__DIR__"axeroom");
	set("exits/wind",__DIR__"whiproom");
	set("exits/thunder",__DIR__"hammerroom");
	set("exits/ice",__DIR__"spearroom");
	set("exits/star",__DIR__"throwingroom");
	set("exits/up",__DIR__"studyroom");
	
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();

}                              

