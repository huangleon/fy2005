inherit ROOM;
void create()
{
        set("short", "����Ů");
        set("long", @LONG
����Ů����ѡ����ӯ��
�̺�է�����£��ཫ���ǲ����ˣ��峪áƵƵ��
���ںã���Ϸ������
��������ž�ҹ��̤�භ�����ഺ��������Ⱥ�档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"xue",
  "south" : __DIR__"lastbridge",
]));
        set("objects", ([
        __DIR__"npc/nu" : 1,
                        ]) );

	set("coor/x",-55);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
