
inherit ROOM;

void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
����������ֻ�з紵���Σ�������ɣ����Ӳ��죬ע��Ⱥɽ�����˲�����Ȼ��
��˼��֮���飡��ǰ����ֻ��һ�����ң����پ��£�ֻ��һ����Լ�ߴ�Ķ�ľ�ţ�
ͨ����¡�Σ���������Ĺȷ��в�ͣ�ض�����
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"bridge",
  		"northwest":	__DIR__"palace_gate",
  		"southwest" : AREA_EASTCOAST"palace_path5",
]));
        set("outdoors", "palace");

	set("coor/x",-110);
	set("coor/y",100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

