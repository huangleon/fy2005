// XXDER@FY
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ܸߣ�����������������Ժǽֻ������һ���һ�㣬�����������ڿ�����
��ա����ܶ��ǻ���ï�ܵ�֦Ҷ�����������������������������������ؿ���
ǰԺ�����䳡�����д�����һ�С�
LONG
        );

   set("item_desc", ([
   		"����":	"���˲ŷ��֣���������ԭ���Ǹ����ѣ�nest��\n",
   ]) );

   set("objects", ([
      	__DIR__"obj/nest": 1,
      	AREA_WUDANG"npc/bird.c":1,
   ]) );

   set("outdoors", "qingping");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",20);
   setup();
}

void init()
{
   add_action("do_search", "search");
   add_action("do_jump", "jump");
}

int do_jump(string arg)
{
   object me, room;

   me = this_player();
   if (!arg || arg!= "down") {
   	tell_object(me,"��ֻ����������jump down��\n");
   	return 1;
   }
   message_vision("$N�����ϰ��������ƮƮ���䵽��Ժǽ�ϡ�\n\n", me);
   room = find_object(__DIR__"wall"); 
   if(!objectp(room)) room=load_object(__DIR__"wall");
      me->move(room);
      message("vision",me->name()+"��ƮƮ���䵽��Ժǽ�ϡ�\n", environment(me), me); 
   return 1;
}

void reset()
{
   object *inv;
   object item1, item2, nest;
   ::reset();

   nest = present("nest", this_object());
   
   if (!present("bird egg", nest)) {
      item1 = new(__DIR__"obj/egg");
      item1->move(nest);
	}
	if (!present("key", nest)) {
      item2 = new(__DIR__"obj/key");
      item2->move(nest);
   }
}
