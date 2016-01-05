inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˴����ӿ���̶ˮ��������ˮ��վ��̶����Ϳ�������ĸо����̹ǵĺ��⡣
̶ˮ���̲�֪�ж��ˮ����һ��ʯ��ˮ�Ӹߴ����³���ھ�ʯ�Ͻ������ɫ��
ˮ����̶�߳����˲�֪���Ļ��ݣ�һ��С��бб��������̶ˮ�ߡ�
LONG
        );

	set("item_desc", ([
	"pond" : "̶ˮ�������ף�����С��СϺ����������������\n",
	"��̶" : "̶ˮ�������ף�����С��СϺ����������������\n",
//	"��ʯ" : "��ʯ��������ˮ�ĳ���γ���һ��������\n",
//	"stone" : "��ʯ��������ˮ�ĳ���γ���һ��������\n",
	]) );
	
	set("objects", ([	
	__DIR__"obj/tree": 1,
	]) );
    set("resource/water",1);
    set("liquid/container","ˮ̶");
    set("liquid/name","��̶ˮ");
    set("outdoors","taoyuan");
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_around", "around");
}

int do_around(string arg)
{
	object me, room;
	int i;
	
	string *rooms = ({"valley", "valley1", "valley2", "valley3"});
	i = random(4);
	me = this_player();
	if(me->is_busy()){
		return notify_fail("������æ��\n");
	}
	tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n");
    room = find_object(__DIR__ + rooms[i]);
	if(!objectp(room)) room=load_object(__DIR__ + rooms[i]);
	me->move(room);

	return 1;
}

void reset ()
{
    object *inv;
    object item1, tree;
    ::reset();
    
    tree = present("tree", this_object());
   	inv = all_inventory(tree);
   	if( !sizeof(inv)) {
    	item1 = new(__DIR__"obj/petal");
       	item1->move(tree);
   }   
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

void do_fishing(object me, object bait){
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
			if (bait->name() == "���" && NATURE_D->get_season() == 1 && !NATURE_D->is_daytime() && random(10)<1){        
         		message_vision("�㹳�ϵ���һ����ɫС�� !!  \n", me);
         		fish = new(__DIR__"obj/rainbowfish");
         		fish->move(me);
         	} else {      
	        	message_vision("�㹳�ϵ���һ������ !!  \n", me);
         		fish = new(__DIR__"obj/fish");
         		fish->move(me);
         	}
         	destruct(bait);
         	break;
      }
   }
   return;
}
