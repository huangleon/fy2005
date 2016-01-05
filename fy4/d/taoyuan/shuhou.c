#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
	
	set("short", "��ƺ");
        set("long", @LONG
��ͩ����ٲȻһ��СС��գ�������ͩ��Ҷʪ���̺�ҶҶ���ġ��������
�飬΢��������ڶ���һ��ʯ��������ʯ�ʶ˶������ذ���С��ƺ���룬С������
��Ϣ�ش����������˸�Ȧ��������һ�����µ�����Ӻ����ϴ������㲻�ɵþ��þ�
��Ϊ֮һ��һ�䲻֪���˵�ʫӿ�����У���Ҷ��ˮ��Ȼȥ ������ط��˼� ����
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"grassland",
	]) );
	set("objects", ([
		"/obj/item/stool" : 2,
	]));
	set("item_desc", ([
           "river" : "һ���峺��С�ӣ�������С�����ζ���\n",
           "С��" : "һ���峺��С�ӣ�������С�����ζ���\n",

	]) );
	set("no_magic", 1);
	set("outdoors","taoyuan");
    set("stools", 3);
	set("coor/x",30);
	set("coor/y",40);
	set("coor/z",0);
	setup();

}

void fish_notify(object obj){
  	object me, room, fish, *inv, bait;
	int i;
	
   	me = this_player();
	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
     	tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");		
		return;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      		message_vision("$N�Ӷ���һ��," + obj->name() + "�ڿ��л���һ��Ư���Ļ���, �㹳������ˮ��. \n" , me);
      		me->start_busy(5);
      		remove_call_out("do_fishing");              
      		call_out("do_fishing", 5, me, bait);			
			return;
		} 
	}
   	tell_object(me, "���õĶ���̫�԰� ? \n");			
	return;

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
         message_vision("�㹳�ϵ���һ������ !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         destruct(bait);
         break;
      }
   }
   return;
}

/*int do_sitdown(){
	
	object me;
	mapping who;
	int i,j,amount;
	
	me = this_player();
	
	amount=query("stools");
	j=-1;
	for(i=0;i<amount;i++)
	{
		if(me==query("sitdown_person/"+(string)i)) return  notify_fail("���Ѿ�������ѽ����\n");		
		if(query("sitdown_person/"+(string)i)&&present(query("sitdown_person/"+(string)i),this_object())) {}
		else j=i;
	}
	if(j==-1)	return notify_fail("ʯ���϶��Ѿ��������ˡ�����\n");
	message_vision("$N��ʯ���ߵ�ʯ��������������\n", me);
	set("sitdown_person/"+(string)j,me);
		
	
	return 1;
}

int do_standup()
{
	object me;
	int i,amount;
	mapping who;
	

	me=this_player();
	amount=query("stools");
	for(i=0;i<amount;i++)
	{	
		if(me==query("sitdown_person/"+(string)i))
		{
			message_vision("$N��ʯ����վ��������\n",me);
			set("sitdown_person/"+(string)i,0);
			return 1;
		}
	}
	return 0;
}*/

int valid_leave(object who,string dir){
	int i;
	mixed *inv;
	object stool;
	inv = all_inventory(this_object());
	for (i=0; i<sizeof(inv); i++){
		if(who == inv[i]->query("sitdown_person")){
			return notify_fail("���������أ������뿪����\n");
		}
	}
	return ::valid_leave(who,dir);
}

int invalid_leave(object player) {
	object *stool_list;
	object stool;
	stool_list = children("/obj/item/stool");
	for(int i=0; i<sizeof(stool_list); i++)
	{
		stool = stool_list[i];
		if (present(stool,this_object()))
		{
			if (player->query_temp("state/sit") && (stool->query("sitdown_person")==player))
			{
				//stool->set("long","ʯ�ʵı��汻ĥ��ʮ�ֹ⻬��������������������������������\n");
				stool->delete("sitdown_person");
				player->delete_temp("state/sit");
			}	
		}
	}
    return 0;
}
