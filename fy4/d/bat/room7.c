inherit ROOM;
void create()
{
        object con,item;
        set("short", "������");
        set("long", @LONG
����һ�䴢���ң����߰���Ķ����ѳ���ɽ���������ӹ�������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"room6",
  		"east" :__DIR__"dating",
	]));
    	set("objects", ([
      		__DIR__"obj/woodcase": 1,
  	]) );
	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
      
}

void   reset() {
	object con, item;
	:: reset();
	con = present("woodcase",this_object());
      	if (con) item = present("bat drug",con);
      	
      	if (!item) {
      		item = new(__DIR__"obj/qidrug");
      		item->move(con);
      	}
      	
}
