inherit ROOM;
void create()
{
        set("short", "���߸�");
        set("long", @LONG
�˸��޶���ÿ����ҹ��΢��ϮϮ�����ǵ�㣻һ�����£��������롣����������
���ƳǾ����۵ס���񷰵����Ψ����һյ�����ﾡ����ΨӢ�����ˡ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"secfloor",
]));
        set("objects", ([
        __DIR__"npc/lin" : 1,
	__DIR__"npc/afei" : 1,
                        ]) );

	set("outdoors","fengyun");
	set("coor/x",-65);
	set("coor/y",15);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
