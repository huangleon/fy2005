#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�������");
	set("long", @LONG
��ǰ����ҫĿ����ͬ�����������岨���㶨��ϸ��������ȫ�ݾ�Ȼ��������
��ɡ��������£���ȫ����������ʽ��ȴ�ƺ�����ˮ���������γ�һ���������
���������ģ������ۣ��ƺ����һ�����������ı�����
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/swordbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();
}


/*
void reset()
{
	object *inv;
	object endtable, item, item1;
	string book;
	string *books = ({"hanmeiforce", "dodgebook", "axsteps", "qiuzhisword"});
	::reset();
	book = books[random(4)];
	endtable = present("endtable", this_object());
	inv = all_inventory(endtable);
	if( !sizeof(inv)) 
	{
		item = new(__DIR__"obj/forcebook");
		item->move(endtable);
		item = new(__DIR__"obj/movebook");
		item->move(endtable);
		item = new(__DIR__"obj/swordbook");
		item->move(endtable);
		item1 = new(__DIR__"obj/" + book);
		item1->move(endtable);
	}
	::reset();
}

*/