inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
ÿ���岽�����Ҹ�һ�š��������мǺţ��ź�����������ÿ��ʮ�������һյ��
��������������ϸ�������ƺ�ÿ���տա�����������������ǰ��չ��һ����������
ͷ��ÿ�������沨ҡ�ڣ��������εĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"corror",
  "west" : __DIR__"corror2",
]));

	set("coor/x",-80);
	set("coor/y",15);
	set("coor/z",0);
        set("objects", ([
        __DIR__"npc/yiku" : 1,
                        ]) );

	setup();
        replace_program(ROOM);
}
