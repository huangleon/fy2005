inherit ROOM;
void create()
{
        set("short", "����ˮ");
        set("long", @LONG
����ˮ�����ƽ�԰�С�
б��ůҡ��䶯���仨��ů���ƺ죬ƻĩ����硣
����Ŀ����ԾС������
������ҡ�����ȣ�������Ӱ���ɹ���Զ������ء�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"jiu",
  "north" : __DIR__"grassroom",
]));
        set("objects", ([
        __DIR__"npc/shui" : 1,
                        ]) );

	set("coor/x",-40);
	set("coor/y",5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
