//XXDER
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ܴ�������������ˮ���ϣ����Բ����ߡ����������Ľż���������
��ˮ�棬΢��Ϯ������������������գ��������˵���һ�����ᡣ����[37m����[32m����
�µ�ˮ�����е�������ȥ����Զ����С�ŵ�ӳ��ˮ�У������￴ȥ����һ�����¡�
LONG
        );

   set("exits", ([ /* sizeof() == 4 */
      "down" : __DIR__"northpond",
   ]));
	
	set("item_desc", ([
		"fish":	"�ۣ��ô�����������е���;ͺ��ˣ�\n",
		"����":	"�ۣ��ô�����������е���;ͺ��ˣ�\n",
		"�ڰ�": "���̫Զ�ˣ���ôҲ���������\n",
		"ʯͷ":	"һ�����̫��ʯ��\n",
		"stone":	"һ�����̫��ʯ��\n",	
	]));
				
   	set("outdoors", "qingping");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",10);
   	setup();
}

int fish_notify(object obj){
   	object me, room, fish, *inv, bait;
   	int i,llvl;

   	me = this_player();
   	llvl = (int)me->query("kar");

	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
     	tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");		
		return 1;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      		message_vision("$N���������Ͼ����Ŀ�ʼ������ \n" , me);
      		me->start_busy(3);
      		if(llvl > 15 && random(20) < llvl) {
            		tell_object(me, "��������ע�⵽��ͷѩ�׵�ʯͷ���ƺ���һ��ڰߡ�\n");
            		me->set_temp("marks/bridge", 1);
      		} else if(random(300) < llvl) {
            	tell_object(me, "��������ע�⵽��ͷѩ�׵�ʯͷ���ƺ���һ��ڰߡ�\n");
            	me->set_temp("marks/bridge", 1);
      		}
      		remove_call_out("do_fishing");              
      		call_out("do_fishing", 5, me, bait);			
			return 1;
		} 
	}
   	tell_object(me, "���õĶ���̫�԰� ? \n");			
	return 1;
}

void do_fishing(object me, object bait)
{
   object 	fish;

   if(me && environment(me) == this_object()) {
   message_vision("$N�ܿ��ֳ�����һ�����, " , me);
   switch (random(3)) {
      case 0:
         message_vision("ȴʲô��û������ ! \n", me);
         break;
      case 1:
         message_vision("ʲô��û������ , ���ȴ������� !!  \n", me);
         destruct(bait);
         break;
      case 2:
         message_vision("�㹳�ϵ���һ���� !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         destruct(bait);
         break;
      }
   }
   return;
}

