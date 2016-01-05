// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�޶�");
        set("long", @LONG
�ղź������ã�������ȴ�����ڵ����������ǻ�Ʒ���Ĺ��ߣ��㲻�ɾ���
���ȣ�����Խ��Խ�ȣ��ƺ��л��ڼ尾���㣬���˼������ܾ�ɫû�иı䣬����
��ʱ������Ů������������������Χ���ȵ���ʯ���㲻��Խ��Խ���
LONG
        );
   set("exits", ([ 
      "north": __DIR__"migong3",
      "south":  __DIR__"migong1",
   ]));
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-20);
	setup();
}

void init()
{
   add_action("do_faint", "faint");
   add_action("do_jump", "jump");
   tell_object(this_player(),RED"\n����ҡ�һΣ����ǻ��Ǽ����û���ε���\n\n"NOR);
}

int do_faint()
{
   object me;

   me = this_player();
   if (me->is_fighting() ) return 0;
   if (me->is_busy() ) return 0;
   message_vision("$N����һ�����Ļ赹�ڵ��ϡ�\n", me);
	me->unconcious();
   call_out("wake", 5 ,me);
   return 1;
}

void wake(object me)
{
   if (me && environment(me) == this_object()) {
	me->revive();
      tell_object(me, "\n\n\n��Ȼͷ�����¼���ˮ�� ....... ��Ȼֻ�м��Σ�ȴ�Ѱ�����ޱȵ�
����������н�ȳ��� ����ϸһ����ԭ���ϱ���һ���ڡ�һ����ȫ�����
Ů��������ˮ�����µ�ˮ�������΢Ц�����������ʹ�����в���һ����
�����Ѿ���ס�˶��ڵķ�λ��\n\n");
      me->set_temp("marks/up", 1);
   }
}


int do_jump(string arg)
{
   object me, room;
   int ml;

   me = this_player();
   ml = (int)me->query_skill("move");
   if (!me->query_temp("marks/up")) return 0;
      if(!arg || (arg != "up" && arg != "��")) return 0;
      if (ml >= 30) {
         tell_object(me, "��������ӯ������������һ�㣬��ǰ��Ӱһ�Σ�ʧȥ��Ů������Ӱ��\n");
         message("vision", "��������ֻ������ǰһ����"+me->name()+"��ʧȥ����Ӱ��\n", environment(me),me);
         room = find_object(__DIR__"huoyan");
         if(!objectp(room)) room = load_object(__DIR__"huoyan");
         me->move(room);
//       me->set("marks/enter_ss/����",1);  
         message("vision", me->name()+"�����������������\n", environment(me), me);
         return 1;
      }
      else {
         tell_object(me, "����������һ����ȴû�취�����ڶ����ϣ�ֻ������������ȥ��\n");
         message("vision", "��������һû����"+me->name()+"��ʧȥ����Ӱ��\n", environment(me), me);
         room = find_object(__DIR__"huoyan");
         if(!objectp(room)) room = load_object(__DIR__"huoyan");
         me->move(room);
         message("vision", me->name()+"����������������\n", environment(me), me);
         return 1;
      }
}

