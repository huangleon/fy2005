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
  "north" : __DIR__"nu",
  "south" : __DIR__"cao",
  "east" : __DIR__"bridge2",
  "west" : __DIR__"taban",
]));
	set("outdoors","fengyun");
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
