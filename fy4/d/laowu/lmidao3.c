// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
��ת�˼����䣬�ص�Խ��Խխ�ˣ��м���������Ҫ�������Ӳſ���ͨ�����ߵ�
�����Ѿ�û�б�ĳ�·�ˣ����϶�����ǽ���ϰ���������ʯ�ӣ��ɼ������Ѿ��к�
��û�����߶��ˡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"lmidao2",
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
   object me, obj, pill;
   int llvl;

   me = this_player();
    llvl = (int)me->query_kar();
   if(!me->query_temp("marks/posion") && !query("got")) {
	set("got",1);
      if (llvl > 19) {  
         if(random(40) <= llvl) {
            message_vision("$N��ǽ��ʯ����һ����Ѱ��\n", me);
            tell_object(me, "������ʯ�����ҵ�һ��С�״�ƿ��\n"); 
            message("vision", me->name()+"����ʯ���м���һ���������뻳�С�\n", environment(me), me);
            obj = new(__DIR__"obj/yuping");
//          pill = new(__DIR__"obj/medicine");
//                pill ->move(obj);
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         } 
         message_vision("$N��ǽ��ʯ����һ����Ѱ��\n", me);
         tell_object(me, "��ʲô��û�ҵ���\n");
         return 1;
      }
      else {
         if(random(200) <= llvl) {
            message_vision("$N��ǽ��ʯ����һ����Ѱ��\n", me);
            tell_object(me, "������ʯ�����ҵ�һ��С�״�ƿ��\n"); 
            message("vision", me->name()+"����ʯ���м���һ���������뻳�С�\n", environment(me), me);
            obj = new(__DIR__"obj/yuping");
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         }
         message_vision("$N��ǽ��ʯ������Ѱ�˺�һ��\n", me);
         tell_object(me, "��ʲô��û�з��֡�\n");
         return 1;
      }
      return 1;
   }
   message_vision("$N��ǽ��ʯ����һ����Ѱ��\n", me);
   tell_object(me, "��ʲô��û���֡�\n");
   return 1;
}
void reset()
{
::reset();
delete("got");
}
