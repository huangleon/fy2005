
inherit ROOM;

void create()
{
        set("short", "���Ƹ�");
        set("long", @LONG
һ������ʦ�Ļ�����������ǽ��, ������·������Ÿ����첼������, ����
����ضѷ���һ��������װ�鼮���������ȴ�տյ����������������ţ�������
��ϥ������һ�����ˣ���ɴ���棬���ۼ��أ��������һ�����á�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"book_room2",
	]));
        set("objects", ([
	__DIR__"npc/taolord2" : 1,
	__DIR__"npc/jing1" : 1,
	__DIR__"obj/desk" : 1,
 	]) );
	set("no_lu_letter",1);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",30);
	setup();
}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) ) {
        item = new(__DIR__"obj/specialbook");
        item->move(con);
        }
}
