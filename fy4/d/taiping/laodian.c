inherit ROOM;
void create()
{
        set("short", "ƽ���ϵ�");
        set("long", @LONG
ƽ���ϵ��Ǹ���ջ��Ҳ�ǼҾ��̡��������һյ��ƣ������Ѳ��ƣ���Ȼ�Ƿ�
�ƣ�Ҳ���پ��������ꡣ�����¹��Ÿ��������յ����������ڱ���������յ�ƣ�
����ȴֻʣһյ������ҹ����˿�����ڻ���綹�������̨�����Ÿ����ˣ�������
�����͵Ƴ����ƺ�û��ע�⵽������� 
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"mroad4",
	]));
        set("item_desc", ([
 	]));
        set("objects", ([
        	__DIR__"npc/oldowner" : 1,
                        ]) );
	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",0);
	set("map","taiping");
	set("cage",1);
	setup();
}

void init(){
	add_action("do_get","get");
	add_action("do_get","pick");
	add_action("do_look","look");
}

int do_look(string arg){
	if (arg=="cage" || arg == "����" || arg=="niaolong" || arg=="birdcage") {
		if (present("birdcage",this_player())) return 0;
		if (present("birdcage",this_object())) return 0;
		if (!query("cage"))
			tell_object(this_player(),"���û��������\n");
			else tell_object(this_player(), "һֻ����ͨ�����������Ű뿪�ţ�����տյ�ʲôҲû�С�\n");
		return 1;
	}
	return 0;
}


int do_get(string arg){
	object birdcage;
	if (arg=="cage" || arg == "����" || arg=="niaolong" || arg=="birdcage") {
		if (!query("cage"))
			return notify_fail("�����Ѿ�����ժ���ˡ�\n");
		message_vision("$N������������������ֻ���������ŵ����Ӷ��ˣ�����ž��һ���䵽���ϡ�\n",this_player());
		birdcage=new(AREA_TAIPING"obj/birdcage");
		if (birdcage) birdcage->move(this_object());
		set("cage",0);
	        set("long", @LONG
ƽ���ϵ��Ǹ���ջ��Ҳ�ǼҾ��̡��������һյ��ƣ������Ѳ��ƣ���Ȼ�Ƿ�
�ƣ�Ҳ���پ��������ꡣ������һ����س������ӻλε��������ڱ���������յ
�ƣ�����ȴֻʣһյ������ҹ����˿�����ڻ���綹�������̨�����Ÿ����ˣ���
���ؿ����͵Ƴ����ƺ�û��ע�⵽������� 
LONG
        );
        	return 1;
        }
        return 0;
}
		
void reset(){
	::reset();
	 set("long", @LONG
ƽ���ϵ��Ǹ���ջ��Ҳ�ǼҾ��̡��������һյ��ƣ������Ѳ��ƣ���Ȼ�Ƿ�
�ƣ�Ҳ���پ��������ꡣ�����¹��Ÿ��������յ����������ڱ���������յ�ƣ�
����ȴֻʣһյ������ҹ����˿�����ڻ���綹�������̨�����Ÿ����ˣ�������
�����͵Ƴ����ƺ�û��ע�⵽������� 
LONG
        );
        set("cage",1);
}

/*
int valid_leave(object me,string dir) {
        object ob,end_room,*inv;
		int i, num;
	
		if( userp(me) && dir == "east" ) {
			num = sizeof(me->query("marks/parrot"));
			
			if ( REWARD_D->riddle_check(me,"�Ѫ����")==6 && num >=6
					&& !me->query("marks/parrot/����") ) {
				end_room = find_object(__DIR__"mroad4");
				if(!objectp(end_room)) 
        			end_room = load_object(__DIR__"mroad4"); 
        		message("vision",me->name()+"���˹�����\n",end_room);
        		me->move(end_room);
				message("vision",me->name()+"���뿪��\n",this_object());
				inv=all_inventory(end_room);
				for (i=0;i<sizeof(inv);i++){
					if (inv[i]->query("marks/parrot_killer")){
						message_vision("$N����$n�е���������վ�����ļ��գ���\n",inv[i],me);
						inv[i]->kill_ob(me);
						me->kill_ob(inv[i]);
					}
				}
				return notify_fail("");		
			}
		}
		return 1;
}*/