inherit ROOM;
void create()
{
        set("short", "����С����");
        set("long", @LONG
С·���������Ȼ��Ϊ������һ���ػ��Ǻ������ϣ����������һ����ͨ��
һ��������С���뷱�ٵķ��Ƴ���ȣ��Ǹ�С���Ե��������塣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north":"/d/libie/stoneroad3",
  "west" : __DIR__"road4",
  "southeast" : __DIR__"road6",
]));
        set("outdoors", "fengyun");
 
	set("coor/x",200);
	set("coor/y",320);
	set("coor/z",0);
	setup();
}
