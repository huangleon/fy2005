inherit ROOM;
void create()
{
        set("short", "���Ͼ�");
        set("long", @LONG
���Ͼƣ��������延��
̴���������׻����������������������۰��࿴��
���������޷�̡�
���Ϸ����ɰ���������ؾ��п��������尲��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hua",
  "northeast" : __DIR__"shui",
]));
        set("objects", ([
        __DIR__"npc/jiu" : 1,
                        ]) );

	set("coor/x",-45);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
