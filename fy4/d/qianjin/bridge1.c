inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�ɻ����ɺ�«״���ڴ�һ�������������������ƻ�żפ��Զ���ƻ���㣬����
��Ӱө�⣬�����ѱ档����ʱ��˪����𣬷��ֽ�Ⱦ�Ʊ̣�Ұ��˥��ܽ�أ���ӳˮ
�ʣ�«έ�к���Ⱥ������߿���ƣ��������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"bridge",
  "west" : __DIR__"grassroom",
]));
        set("objects", ([
        __DIR__"npc/piaoke" : 1,
        __DIR__"npc/piaoke2" :1,
                        ]) );

	set("outdoors","fengyun");
	set("coor/x",-35);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-35);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
