inherit ROOM;
void create()
{
        set("short", "�����鱦��");
        set("long", @LONG
�鱦��������ǿ�ǧ������ɵ�����������������֣�����������֮�С�������
������������ȭͷ��С���������Ρ����۰�����ա����ܵ�ǽ�Ϲ����˸��ֽ�����
Ʒ�͸��ֻ�����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );

        	set("coor/x",-1);
        	set("coor/y",-10);
          set("coor/z",-300);
	setup();
       replace_program(ROOM);
}
