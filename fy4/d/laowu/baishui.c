// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
�߽�������ԭ��ˮɫ����������ɫ��ֻ�ǵ�ӳ���ϰ��ƣ�����ԶԶ������
����һƬ��ɫ�����߲�����ľ��ˮ���ʼ����㣬�Ե�������֣�����΢�����
֮�£���Ȼ����ˮ��ζ������˲��ɰ������档
LONG
        );
   	set("exits", ([ 
      		"west" : __DIR__"valley",
   	]));
   	set("objects", ([
		__DIR__"npc/bear": 1,
	]) );
   	set("outdoors","laowu");
	set("coor/x",190);
	set("coor/y",190);
	set("coor/z",20);
	setup();
}

void init()
{
   	add_action("do_swim", "swim");
}

int do_swim(string arg)
{
   	object me;
	me = this_player();
   	message_vision("$N�����ˮ�У�", me);
   	tell_object(me, "��ˮ��Ĵ̹ǣ��㲻�ɵش��˸���ս���Ͻ��ص��˺��ߡ�\n");
   	message("vision", "���˸���ս���ַɿ�������˰���\n", environment(me), me);
   	me->receive_damage("kee",50);
   	me->set_temp("last_damage_from","�ڰ�ˮ���ﶳ���ˡ�\n");
   	return 1;
}

void kite_notify(object obj, int i)
{
   	object  me, room;
   	int j;
	
   	me = this_player();
   	message_vision("ͻȻһ��΢�����"+obj->name()+"����������������Խ��Խ�ߡ�\n\n" , me);
	tell_object(me, me->name()+"���е�"+obj->name()+"Խ��Խ�ߡ� \n");
	message_vision("ֻ��һ�����õ������Ӹ߿մ����� \n", me);
	call_out("boat_come", 2, me);
	destruct(obj);
   	return; 
}

void boat_come(object me)
{
   	object  boat, *inv, ob;
   	int i;

   	if (query("exits/down")) return ;
   	if (!objectp(boat=find_object(__DIR__"boat")))
      		boat=load_object(__DIR__"boat");
   		inv=all_inventory(boat);
   	for(i=0; i<sizeof(inv); i++) {
      	ob = inv[i];
      	if(living(ob)){
         	message("vision","���Σ����ϻ���û��˿��������\n",this_object()); 
         	return;
      	}
   	}
   	message("vision","���˰��Σ�һҶС�ۻ����ش����е����������˺��ߡ�\n",this_object()); 
   	boat->set("exits/up",__DIR__"baishui");
   	set("exits/down",__DIR__"boat");
   	call_out("boat_leave",10,boat);
   	return ;
}

void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","һ��΢�������С�������˰��ߡ�\n",this_object()); 
	message("vision","һ��΢�������С�������˰��ߡ�\n",boat); 
        return;
}

int valid_leave(object me, string dir)
{
   object *inv, boat, ob;
   int i;

   if (userp(me) && dir == "down") {
      boat=find_object(__DIR__"boat");
      if (!objectp(boat))
         boat=load_object(__DIR__"boat");
         inv=all_inventory(boat);
            for(i=0; i<sizeof(inv); i++) {
               ob = inv[i];
               if(living(ob)){
                  tell_object(me, "��̫С�ˣ�ֻ�ܳ���һ���ˡ�\n");      
                  return notify_fail("");
               }
           }
   }
   return 1;
}
