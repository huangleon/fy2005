// Room: /d/oldpine/riverbank2.c

inherit ROOM;

void create()
{
        set("short", "ɽ��֮��");
        set("long", @LONG
��������վ��һ��ɽ���е���ʯ�ϣ�һ��Сʯ�����߸ߵش����ͷ������ɽ
�����ߵ�ʯ�ڣ�һ���ٲ�������ı�����Զ������һ�����ߵ������ϴ���������
LONG
        );
        set("item_desc", ([
                "cliff":
                        "�����ɽ�ڱȱ��߸߶��Ե��˵㣬���ǶԷ��˶�����Ҫ����ȥ��Ȼ\n"
                        "����һ�β�ࡣ\n"
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"waterfall",
  "south" : __DIR__"riverbank1",
]));
        set("outdoors", "oldpine");
        set("resource/water", 1);
        set("liquid/name","ɽ��ˮ");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
