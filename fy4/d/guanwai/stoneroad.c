// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "ʯɽ");
        set("long", @LONG
�����ɽ����ǹ�ͺͺ�ģ���ͬ�ڽ�������ɫ������ɽ�ͣ����ɫ��ɽ��ֻ��
����һЩ��С�Ĺ�ľ����ЩСɽ����������ȥ��һ�룬һ·������ɽ·���಻ʱ��
���Ÿղ������ľ���ʯ�ϡ�һ��С·˳��ɽ�����ѵ�����Զ����·�ľ�ͷ��һ����
ɫ��Сʯ�ݡ�ʯ��ǰ��һ��ˮ��,�����ǹ���·���˽�ʵ�.
LONG
        );

    set("resource/water", 1);
    set("liquid/container", "ˮ��");   	
    set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"work",
		"west" : __DIR__"stonehouse",
	]));
    set("outdoors", "guanwai");

	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

