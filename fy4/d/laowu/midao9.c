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
		  "south" : __DIR__"midao7",
	]));
	set("coor/x",100);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}


void init()
{
   add_action("do_search", "search");
}

int do_search(string arg)
{
   object me, obj;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if(!me->query_temp("marks/posion") && !query("got")) {
	set("got",1);
      if (llvl > 19) {  
         if(random(40) <= llvl) {
            message_vision("$N�ںڰ���һ����Ѱ��\n", me);
            tell_object(me, "������ʯ�����ҵ�һ��Сƿ�ӡ�\n"); 
            obj = new(__DIR__"obj/yuping");
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         } 
         message_vision("$N�ںڰ���һ����Ѱ��\n", me);
         tell_object(me, "��ʲô��û�ҵ���\n");
         return 1;
      }
      else {
         if(random(200) <= llvl) {
            message_vision("$N�ںڰ���һ����Ѱ��\n", me);
            tell_object(me, "������ʯ�����ҵ�һ��Сƿ��\n"); 
            obj = new(__DIR__"obj/yuping");
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         }
         message_vision("$N�ںڰ�����Ѱ�˺�һ��\n", me);
         tell_object(me, "��ʲô��û�з��֡�\n");
         return 1;
      }
      return 1;
   }
   message_vision("$N�ںڰ���һ����Ѱ��\n", me);
   tell_object(me, "��ʲô��û���֡�\n");
   return 1;
}


void light_notify(object obj, int i)
{
   object *inv, me, room;
   int j;
	
   me = this_player();
   switch(i){
      case 1:
         message_vision(obj->name() + "�����Ĺ��������ص���\n\n" , me);
         room = find_object(__DIR__"lmidao3");
         if(!objectp(room)) room=load_object(__DIR__"lmidao3");
         inv = all_inventory(this_object());
         for(j=0; j<sizeof(inv); j++) {
            inv[j]->move(room,1);
         }
      break;
   }
   return;
}


void reset()
{
::reset();
delete("got");
}
