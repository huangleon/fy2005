//XXDER
inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
������ǰ����յ��鷿����������������飬�������书��Ϊ���黯����û��
������һ����Ҳ��˾������ǽ�Ϲ��˼����ֻ�������֪���Ժ��˵��ֱʣ��Ǽ�
����ȴ�ư����յ��ױʡ����ڿ�ǽ����һ�ź�ľ����������ǰ����һ�����ӡ�
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"garden",
   ]));

   set("item_desc", ([
      	"writing": "ֻ���ּ����д��ᣬ����������ˮһ���ǳɡ�\n",
      	"��": "ֻ���ּ����д��ᣬ����������ˮһ���ǳɡ�\n",
   ]) );

   set("objects", ([
      __DIR__"obj/desk": 1,
      __DIR__"obj/wall": 1,
      __DIR__"npc/qingm" : 1,
   ]) );

	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset()
{
	   object *inv;
	   object item1, item2, desk, wall;
	   ::reset();
	   	   
   		desk = present("desk", this_object());
   		wall = present("wall", this_object());

	   if (!present("silk bag", desk)) {
	   		item2 = new(__DIR__"obj/bag");
	      	item2->move(desk);
	   }
	   	
	   if (!present("letter", desk))	{
			item1 = new(__DIR__"obj/letter");
	      	item1->move(desk);
	   }
	   
	   if (!present("kite",wall)) {
	   		item1 = new(__DIR__"npc/obj/kite");
	      	item1->move(wall);
	   }
   
}
