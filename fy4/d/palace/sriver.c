
inherit ROOM;

void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
�������֣�ǰ���ֳ�һ���峺����Ȫ����������ļ�ɽ����Ȫ����ɽ�ϣ�����
���𵹹ң����ڶ��£����齦�������������֣�һ���������ĺ��⣬������Ƣ��
��Ȫ����һ����ɽ������ɽ��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"gate",
  "east" : __DIR__"stone",
]));
        set("outdoors", "palace");
        set("resource/water",1);
         set("liquid/name","��Ȫˮ");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

