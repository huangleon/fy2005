inherit ROOM;
void create()
{
        set("short", "���ϻ�");
        set("long", @LONG
���ϻ�����ˮ����ѿ��
ǳ��ˮ������ۣ�Ũ���������ϼ���������ɼҡ�
�����ף����������ڡ�
ˮ��������ޣ���������ů��������˼���ޡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cao",
  "east" : __DIR__"jiu",
]));
        set("objects", ([
        __DIR__"npc/hua" : 1,
                        ]) );

	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
