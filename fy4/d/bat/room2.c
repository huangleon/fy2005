inherit ROOM;
void create()
{
        object con,item;
        set("short", "����");
        set("long", @LONG
����һ�������ĵ�������ս������ŵ�һ�ɴ̱ǵ�ҩ�ݵ�ζ������������ң�
�ƺ��ոձ��˷��������ָ�����ƿ�޶ѵĵ������ǡ���ǽ���Ÿ���ҩ��

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"zoulang1",
	]));
    	set("objects", ([
      		__DIR__"obj/case": 1,
       		"/obj/specials/ding/ding_bat" : 1,
       		__DIR__"npc/xunluo2" : 1,
	       
  	]) );
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",-10);
	setup();

}

int valid_leave(object me,string dir)
{
        object ob;
	if(userp(me) && me->query("class")!="bat" && dir == "south" && ob=present("xunluo shiwei",this_object()))
	if (ob->query("name")=="Ѳ������")
	{
	message_vision("$N��$n�����󵨣������Ҵ�����!\n",ob,me);
	return notify_fail("");
	}
	return 1;
}

void   reset() {
	object con, item;
	:: reset();
	con = present("case",this_object());
      	if (con) item = present("bat drug",con);
      	
      	if (!item) {
      		item = new(__DIR__"obj/drug");
      		item->move(con);
      	}
      	
}
