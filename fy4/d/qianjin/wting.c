inherit ROOM;
void create()
{
        set("short", "��ƫ��");
        set("long", @LONG
����һ��̨���������衣���������������������ζ������������¡���ʱ��
ɫ������������ҫ����ͬ���ա��������㣬���׷��档���;��黶Ц������������
һ�����������ȡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"corror",
  "east" : __DIR__"tading",
]));
       set("objects", ([
        __DIR__"npc/haoke" : 2,
	__DIR__"npc/peijiunu" : 4,
                        ]) );

	set("coor/x",-70);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
