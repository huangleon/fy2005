inherit ROOM;

void create()
{
        set("short", "��̨");
        set("long", @LONG
����һ��СС����̨�������������һֱ����ɽ�š�ǿ����ɽ�紵�������ϣ�
����е��������ˬ������һ�����еĺ�ȥ����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"bedroom",
]));
        set("objects", ([
                __DIR__"npc/pigeon" : 2,
        ]) );

        set("outdoors", "chuenyu");
	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",30);
	setup();
}

