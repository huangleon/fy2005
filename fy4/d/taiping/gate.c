inherit ROOM;
void create()
{
        set("short", "���ׯ");
        set("long", @LONG
�����������ׯԺ����ڵĴ��Ž��գ����������ɸ�ǽ��ǽ�ϵ����ŷ浶��
����û���ˣ��������������κε����죬����ׯԺ������һ��Ī����������ɭ֮�С�
ׯԺռ�ؼ��㣬��ȫ��������Χ��û�н������ݣ�����û��һ�ã�ȴ���һ��Ϫ����
Ϫ��֮�����Ǹ�ǽ������ڶ�װ����դ��
LONG
        );
        set("exits", ([ 
		"northwest": __DIR__"eroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([  
		"door": "���Źص������ģ�����û��һ˿������\n",
		"����": "���Źص������ģ�����û��һ˿������\n",
	]));
	
	 set("objects", ([
        	__DIR__"npc/whiteman_a" : 1,
        	__DIR__"npc/whiteman_b" : 1,
     ]) );
	
	set("coor/x",40);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();

}



void init() {
	add_action("do_knock","knock");
	add_action("do_push","push");
}


int do_knock(string arg) {
	
	if (arg=="door" || arg =="����" || arg =="��"){
		message_vision("$N��������˼��£�������һ˿����Ҳû�С�\n",this_player());
		return 1;
	}
	return 0;
}


int do_push(string arg) {
	
	if (arg=="door" || arg =="����" || arg =="��") {
		message_vision("$N�����������ţ�������˿������\n",this_player());
		return 1;
	}
	return 0;
}


void init_mission(int count, int exp, object me){
	
	object robber,*inv;
	int i,j;
	
	inv = all_inventory();
	
	for (i=0;i<count;i++) {
		robber=new(__DIR__"npc/blackman");
		robber->move(this_object());
		
		if (exp < 6000000)	exp = 6000000;
		robber->set("combat_exp",exp);
		"/feature/nada"->reset_npc(robber);
			
		if (robber->query("max_kee")> 9000)
		robber->set("max_kee",9000);
		if (robber->query("max_sen")>9000)
		robber->set("max_sen",9000);
		if (robber->query("max_gin")>9000)
		robber->set("max_gin",9000);
		
		robber->full_me();
		SMART_D->auto_npc_setup(robber, "����ׯ��", 200, 180, 1, "/obj/weapon/", "random", "random", 1); 	
        
        robber->set("count", count);
        robber->set("mission_target",me);
        
    	for (j=0; j<sizeof(inv);j++) {
    		if (inv[j]->query("sanye")){
    			robber->kill_ob(inv[j]);
    			inv[j]->kill_ob(robber);
    		}
    	}
    	if (environment(me)==environment(robber)) {
    		robber->kill_ob(me);
    		me->kill_ob(robber);
    	}
    }
    
    return;
} 
	
	