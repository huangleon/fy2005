#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ɽ�屳��");
        set("long", @LONG
���ʯת������ǰͻȻһ����ɽ���ڴ���Ȼ���ʣ�����ǰ�ڿ��������ο���
[36m��ʯ[32m����ǰһ��С·��֪��ʱ�����������Ϣ�����ѽ��£�Զ���������ƣ�������
�ң�����������ƺ�������������Ҫפ��ϸ����������ȴ����Ӱ���١�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"valley2",
	]) );

	set("item_desc", ([
		"stone" : "��ʯ�Ϲ���������ȴ�������Σ��ƺ�����һ�ƾͿ��Կ��ˡ�\n",
		"rock" : "��ʯ�Ϲ���������ȴ�������Σ��ƺ�����һ�ƾͿ��Կ��ˡ�\n",
		"��ʯ" : "��ʯ�Ϲ���������ȴ�������Σ��ƺ�����һ�ƾͿ��Կ��ˡ�\n",
		"north" : "Сɽ���к�����ģ���ʲôҲ���������\n",
	]) );
	set("no_magic", 1);	
	set("no_fly", 1);	

   	set("outdoors","taoyuan");
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init ()
{
	add_action("do_push", "push");

   add_action("do_listen", "listen");
   add_action("do_southeast", "go");
}

int do_southeast(string arg)
{
   object me, room;
   me = this_player();

   if (arg == "southeast")
   if(me->query_temp("marks/listen")) {
/*      if (ANNIE_D->check_buff(me,"fugitive")>0) {
   			tell_object(me,"���ذ��������ǲ�Ҫȥ����Ǹ�������Դ֮���˰ɡ�\n");
      		return 1;
      }*/
      tell_object(me, "������С·�������ǰ�������֮����\n\n");
      message("vision", me->name(me)+"�������ѵ�ɽ·ת�˼�ת��ʧȥ����Ӱ��\n", environment(me),me );
      room = find_object(__DIR__"taovillage");
      if(!objectp(room)) room=load_object(__DIR__"taovillage");
      me->move(room);
      return 1;
   }
   return 0;
}

int do_listen(string arg)
{
   object me, room;
   me = this_player();

   tell_object(me,"�����������ޣ�����ϸ������������������ԼԼ�Ӷ��ϱߴ�����\n");
   message("vision",me->name(me)+"ͻȻס�㣬�ƺ��ڲ��������ʲô��\n", environment(me),me);
   tell_object(me, HIG"\n����ƽ���滺��һϴ��ô�������ɱ��֮�������Ȼ���ܵ����������\n\n"NOR);
   tell_object(me, "������ϸ���˿��Ǹ������ƺ���һ��С·���������������������֮����\n", me);
   me->set_temp("marks/listen", 1);	

   return 1;
}
void close_path()
{
	if( query("exits/north") ) {
    message("vision","����ǣ����ʯ�����غ����ˡ�\n",this_object() );
    delete("exits/north");
    }
}

int do_push(string arg)
{
	object me;
    me = this_player();
    if( arg=="stone" || arg =="��ʯ" || arg == "rock") {
    	message_vision("$N����ʯ�������һ�ƣ���ʯ������ת��������չ�ֳ�һ��ɽ����\n", me);
		set("exits/north", __DIR__"treasure");
		call_out("close_path", 3);
	}
	else {
		write("��Ҫ��ʲô�أ�\n");
	}
	return 1;	
 }
