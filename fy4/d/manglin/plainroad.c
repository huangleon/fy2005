//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "ƽԭ·");
	set("long", @LONG
����Ա����ϣ����ƽ�ƽ��·������Сʯ�ӣ�һ�����������Ϸ��ͱ�����չ��
����������棬������Ϊ�ѽš������Ե���ľԽ��Խ�٣������ƻ������Ҹ��ط�
��Ϣһ�¡������֧·�������ķ��Ƶ�������������һֱͨ��[33m������[32m��
LONG
	   );
	set("exits", 
	   ([ 
	     	"north" : __DIR__"woodsroad",
	     	"south" : __DIR__"southsearoad",
         	"west" : AREA_CHENXIANG"fydao3",
	    ]));
	set("outdoors", "baiyun");
	set("NONPC",1);
	set("coor/x",60);
	set("coor/y",-220);
	set("coor/z",10);
	setup();
}
