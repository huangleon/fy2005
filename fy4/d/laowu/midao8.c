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
  "west" : __DIR__"midao7",
]));
	set("coor/x",110);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_search", "search");
   add_action("do_push", "push");
}


int do_push(string arg)
{
   object me;
   int flvl;

   me = this_player();
   flvl = (int)me->query_str();
   if (!arg || (arg != "stone" && arg != "ʯͷ")) return 0;
   if (me->query_temp("marks/foundstone")) {
      if(flvl >= 20) {
         tell_object(me, "��������˫�ۣ�ʹ��������������ʯ��ȥ��\n");
         message_vision("�ڰ���ֻ����һ˿��͸��������Խ��Խ������¶�������ڣ� \n",me);
         set("exits/out", __DIR__"dongkou");
         call_out("close_path", 1);
         return 1;
      } 
      else {
         tell_object(me, "��������˫�ۣ�ʹ��������������ʯ��ȥ��ʯͷֻ�����Իζ��˼��¡�\n");
         return 1;
      }
   }
   return 0;
}

void close_path()
{
   if(!query("exits/out") ) return;
   message("vision", "ֻ����֨֨��ʯͷ�����������˶��ڣ��ڰ���������һ�С�\n", this_object() );
   delete("exits/out");

}

int do_search(string arg)
{
   object me, obj;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if(random(200) < llvl) {
      		message_vision("$N�ںڰ����Ĵ�������\n", me);
      		tell_object(me, "��������һ���ʯ��ҡ��ҡ�ƺ���Щ�ɶ���\n");
      		me->set_temp("marks/foundstone", 1);
      return 1;
   }
   message_vision("$N�ںڰ����Ĵ�������\n", me);
   tell_object(me, "��û���κη��֡� \n");
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
         room = find_object(__DIR__"lmidao4");
         if(!objectp(room)) room=load_object(__DIR__"lmidao4");
         inv = all_inventory(this_object());
         for(j=0; j<sizeof(inv); j++) {
            inv[j]->move(room,1);
         }
      break;
   }
   return;
}
