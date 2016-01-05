
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
���������ߣ����Եĵ��̶�������������ġ�ƽ���ϵꡱ���Ǹ���ջ��Ҳ�Ǽ�
���̣�����������ﴫ�����������������������ֵ������ֵ���Ȼ�Ƿ��������һ
������Ҷ��糺��������������糯¶�������ݵ���֬����һ������ͨͨ��С����
���˸������ļ��ˡ�
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"laodian",
		"east" : __DIR__"tiepu",
		"south": __DIR__"mroad45",
		"north": __DIR__"mroad3",
	]));
        set("outdoors", "taiping");
	
	if (random(3)) {
		set("objects", ([
	        	__DIR__"npc/drunk" : 2,
	        ]) );
	} else {
		set("objects", ([
	        	__DIR__"npc/fakedrunk": 2,
	        ]) );
	}
	
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}

void reset(){
	if (random(4)) {
		set("objects", ([
	        	__DIR__"npc/drunk" : 2,
	        ]) );
	} else {
		set("objects", ([
	        	__DIR__"npc/fakedrunk": 2,
	        ]) );
	}
	::reset();	
}

void init(){	
		object me, *inv;
		int num, i;
		
		me = this_player();
		
		num = sizeof(me->query("marks/parrot"));
		if ( REWARD_D->riddle_check(me,"�Ѫ����")==6 && num >=6
				&& !me->query("marks/parrot/����") ) {
				inv=all_inventory(this_object());
					for (i=0;i<sizeof(inv);i++){
						if (inv[i]->query("marks/parrot_killer")){
							message_vision("$N����$n�е���������������ļ��գ���\n",inv[i],me);
							inv[i]->kill_ob(me);
							me->kill_ob(inv[i]);
						}
					}
				}
		return;
	
}	