inherit ROOM;
void create()
{
        set("short", "����ѩ");
        set("long", @LONG
����ѩ���缱�黹�ࡣ
��Ƭ��ʱ���񻧣��ػ�������β�����������ĥ��
��ˮԶ�����ɫ��͡�
����Ī˼��Է���������������˸裬��������Σ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"liu",
  "southwest" : __DIR__"nu",
]));
        set("objects", ([
        __DIR__"npc/xue" : 1,
                        ]) );

	set("coor/x",-50);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
