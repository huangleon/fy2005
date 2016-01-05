// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
ת�˼����䣬�붴�����ǰ���ֲ�����ָ����Χ��ʱ����С�����ӹ���ɳɳ
����������η�������ͷȴ�Ѳ�֪��ʱ�ĵ�·����������Ҳ�ֲ��嶫���ϱ���ֻ��
�����ŷ���׳�ŵ�����������ǰ�ߡ�
LONG
        );
   set("exits", ([ 
      "south" : __DIR__"midao5",
   ]));
	set("coor/x",90);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_search", "search");
   add_action("do_look", "look");
}

int do_look(string arg)
{
   object me;

   me = this_player();
   if (!arg || (arg != "ͭ��" && arg != "light" && arg != "lamp"))
      return 0;
   if(me->query_temp("marks/foundlight"))
      tell_object(me, "ͭ�����ƺ���ע�����͡�\n");
   return 1;
}

int do_search(string arg)
{
   object me;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if (!arg) {
      if(random(100) < llvl) {
         tell_object(me, "����ǽ����������һ����ͭ�ƵĶ�����\n");
         me->set_temp("marks/foundlight", 1);
         return 1;
      }
      message_vision("$N�ںڰ���������һ��\n", me);
      tell_object(me, "��û���κη��֡�\n");
      return 1;
   }
   return 0;
}

void light_notify(object obj, int i)
{
   object *inv, me, room;
   int j;
	
   me = this_player();
   if(me->query_temp("marks/foundlight")){
      switch (i) { 
	      case 0:
	         message_vision("$N��" + obj->name() + "��ȼ��ǽ���ϵĵơ�\n\n" , me);
	         room = find_object(__DIR__"lmidao1");
	         if(!objectp(room)) room=load_object(__DIR__"lmidao1");
	         inv = all_inventory(this_object());
	         for(j=0; j<sizeof(inv); j++) {
	            inv[j]->move(room,1);
	         }
	      break;
	      case 1:
	         message_vision(obj->name() + "�����Ĺ��������ص���\n\n" , me);
	        room = find_object(__DIR__"lmidao1");
	         if(!objectp(room)) room=load_object(__DIR__"lmidao1");
	         inv = all_inventory(this_object());
	         for(j=0; j<sizeof(inv); j++) {
	            inv[j]->move(room,1);
	         }
	      break;
	      }
   }
   return;
}
