inherit ROOM;
void create()
{
    object con,item;
    set("short", "���Ͻ�¥");
    set("long", @LONG
��¥�Ϲ���һ��ͭ�ӣ�ÿ���н���������س������Ǿ�����Ϊ���������ٱ�����
�˽���������¥���м���һ���޴����¯������װ�����Ƿ࣬�Ա�������������¥
�ﻹ��װ��һ�Ż��ڣ�ǽ���ﻹ����һЩ�����衣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ewall10",
	"west"  : __DIR__"swall1", 
      ]));
    set("objects", ([
	__DIR__"npc/wall_soldier" : 3,
	__DIR__"obj/corner" : 1,
	__DIR__"obj/bomb": 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",300);
    set("coor/y",-300);
    set("coor/z",30);
    setup();
    con = present("corner",this_object());
    item = present("bomb",this_object());
    if( con && item)
	item->move(con);

}
