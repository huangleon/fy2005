inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����£�ƫ�����ɼҡ�
ˮ����������������ҡ��Ӱ�߽��ߣ�ƫ�Ʒ���鶡�
�⾰�ã��������б��
��¶��������Ӱ�����紵���֦������˼���ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"grassroom",
  "northwest" : __DIR__"liu",
]));
        set("objects", ([
        __DIR__"npc/yue" : 1,
                        ]) );

	set("coor/x",-40);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
