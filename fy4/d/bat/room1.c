inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������������Ũ��Ũ�ü������������ܻ��� İ���ĵط���İ����Ů�ˣ��ڰ����� 
���������ĸ������ֿܵ����ֿ��µ��ջ�......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zoulang1",
]));
        set("objects", ([
        __DIR__"npc/woman" : 1,
                        ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
