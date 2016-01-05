#include <ansi.h>
inherit SMART_NPC;

mapping *way;
object *protector;

mapping *read_table(string);

int  init_escort(object me, int exp);

void go_now();
void get_quest(string file);
void set_protector(object *prot);
void del_marks_giver();
void give_reward();
void to_rob();
void be_protect();



void create()
{
    	object ob;
    	set_name("�ֹ���", ({ "fat lady","fatty" }) );
    	set("gender", "Ů��" );
    	set("age", 19);
    	
    	set("NO_KILL",1);
    	set("route","/d/biancheng/escort_1");
    	set("escortee","passive");
    	set("pfm_chance", 20);
    	set("robber1",__DIR__"ass1");
    	set("rob_num",1);
    	 	
    	set("combat_exp", 100000);
    	set("attitude", "friendly");
    	
    	set("chat_chance", 5);
    	set("chat_msg",({
    			query("name")+ "˵�����㡢���㡢���������������\n",
//    			"�ֹ���˵�����ж�Զ���쵽��ô��\n",
        }) );
    	
    	set("chat_chance_combat",100);
    	set("chat_msg_combat", ({
    			(: be_protect :),
        }) );
	
    	setup();
       	carry_object("/obj/armor/cloth")->wear();
}


int		init_escort(object me, int exp) {
		
		object *team, escortee;
		int i;
						
		// ����·��
		get_quest(query("route"));
		
		// ����escorter/escortee��ϵ
		team = me->query_team();
		if (!team || !sizeof(team))	{
			team=({me});
			set_protector(team);
			me->set_temp("protecting",this_object());
		}	else	{
			set_protector(team);
			for(i=0;i<sizeof(team);i++)
       			team[i]->set_temp("protecting",this_object());
    	}
		me->set_leader(this_object());
				
    	go_now();
		return 1;
}	

int random_move()
{
		mapping exits;
		string *dirs, direction;
		object env;
		
		if( !mapp(exits = environment()->query("exits")) ) return 0;
		
		dirs = keys (exits);
		direction = dirs[random(sizeof(dirs))];
		command("go " + direction);
		return 1;
}

//overwrite base npc random_move() function
void go()
{
    	int i,j;
    	object robber;
    	string *cmds;
    	
    	remove_call_out("go");
    	for(i=0;i<sizeof(way);i++)
    	{
        	if (base_name(environment()) != way[i]["room_file"]) continue;
        	cmds=explode(way[i]["cmd_table"],";");
        	break;
    	}
    
    	robber=present("veiled man",environment());
    	if (this_object()->is_fighting() || (robber && robber->name()=="������"))
    	{
        	call_out("go",15);
        	return;
    	}
    	
    	if (!SMART_D->check_health(this_object(),50)){
    		command("say ���У�ʹ�����ˣ����Ҵ�������");
    		add_temp("bandit/hurt",1);
    		message_vision("$N�������˼���������ʼ�˹����ˡ�\n",this_object());
    		call_out("go",15);
    		return;
    	}
    	
    	if (random(100)<15)
    	{
        	to_rob();
        	call_out("go",15);
        	return;
    	}
    	
    	// �Թ���δ�������С�����Ԥ����
    	if (i>=sizeof(way))
    	{   
        	random_move();
        	message_vision("$N�Ĵ����˿����ƺ��ò������⡣\n",this_object());
        	call_out("go",5);
        	return;
    	}
    	
    	for(j=0;j<sizeof(cmds);j++) {
//        	command("say "+ cmds[j] +"");
        	command(cmds[j]);
    	}
    	
    	if (way[i]["delay_time"]<0)
    	{
        	give_reward();
        	return;
    	}
    	call_out("go",way[i]["delay_time"]);
    	return;
}	


void be_protect()	{
    	
    	int i,j,flag;
    	object *inv,*enemy;
	
    	inv=all_inventory(environment());
    	enemy=query_enemy();
    	
    	if (!enemy || sizeof(enemy)<1)	return;
    	
// if one of the protectors wants to kill... then heis out of the loop
    	for(j=0;j<sizeof(enemy);j++)
        	enemy[j]->delete_temp("protecting");

    	for (i=0;i<sizeof(inv);i++)
        if (inv[i]->query_temp("protecting")==this_object())
        {
            flag=1;
            for(j=0;j<sizeof(enemy);j++)
            {
                if (!inv[i]->is_fighting(enemy[j])) {
                	inv[i]->kill_ob(enemy[j]);
                	enemy[j]->kill_ob(inv[i]);
                }
                if (query("escortee")== "passive") {
                	enemy[j]->remove_killer(this_object());
                	remove_killer(enemy[j]);
                }
            }
        }
    	  	
    	
    	if (query("escortee")!="passive" && is_fighting())
    		auto_smart_fight(query("pfm_chance"));
    	else
    		message_vision("��С�����У��������������������˽١��١���ɫ�ˣ�\n",this_object());
    	   	
    	return;
}

        
void get_quest(string file)
{   
    	way=read_table(file);
//    	CHANNEL_D->do_sys_channel("sys",sprintf("%O",way));
}

void to_rob()
{
    	int i, num;
    	object robber;
    	int exp;
    	object *inv;
    
    	exp=this_object()->query("combat_exp");
    	inv=all_inventory(environment());

// Some players joined team after getting mission.....
    	for (i=0;i<sizeof(inv);i++) {
	    	if ( inv[i]->query_temp("protecting")==this_object())
	       	{
	         	if (inv[i]->query("combat_exp")>exp) 
	         		exp = inv[i]->query("combat_exp");
	        }
    	}
    	
    	num = query("rob_num");
    	
    	add_temp("bandit/bandit",num);
    	    	    	
    	message_vision("��Ȼ������"+chinese_number(num)+"�������ˣ�\n",this_object());
    	message_vision(CYN"�����˽е���Թ��ͷծ������û�¶���������������������\n"NOR, this_object());
    	  	
    	for (i=0;i<num;i++)
    	{
        	robber=new(query("robber1"));
        	robber->move(environment());
        	robber->set("combat_exp",exp);
        	"/feature/nada"->reset_npc(robber);
    		
	   		robber->full_me();
    		SMART_D->auto_npc_setup(robber, "������", 200, 180, 1, "/obj/weapon/", "random", "random", 1); 	
        	robber->kill_ob(this_object());
        	kill_ob(robber);
        	robber->set_leader(this_object());
    	}
    	  	
    	be_protect();
}
	
mapping *read_table(string file)
{
    	string *line, *field, *format;
    	mapping *data;
    	int i, rn, fn;

    	line = explode(read_file(file), "\n");
    	data = ({});
    	for(i=0; i<sizeof(line); i++) {
        	if( line[i]=="" || line[i][0]=='#' ) continue;
        	if( !pointerp(field) ) {
            		field = explode( line[i], ":" );
            		continue;
        	}
        	if( !pointerp(format) ) {
            		format = explode( line[i], ":" );
            		continue;
        	}
        	break;
    	}

    	for( rn = 0, fn = 0; i<sizeof(line); i++) {
	        if( line[i]=="" || line[i][0]=='#' ) continue;
	        if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
	        sscanf( line[i], format[fn], data[rn][field[fn]] );
	        fn = (++fn) % sizeof(field);
	        if( !fn ) ++rn;
    	}
    	return data;
}

void set_protector(object *prot)
	{ protector=prot; }

object *query_protector()
	{ return protector; }


void die()
{
    	del_marks_giver();		//added by justdoit
    	::die();
}

void give_reward()
{   
    	object *inv,*pro_team;
    	int values,i,reward;
		int reward_p, reward_e,num,num2,total;
	
    	    	if (arrayp(protector)) 
    	{
           	pro_team=protector;
        	if (sizeof(pro_team))  	{    	        		            		
        		for(i=0;i<sizeof(pro_team);i++)
        		{
            		if (!objectp(pro_team[i])) continue;
            			              	   	
              		if (!REWARD_D->check_m_success(pro_team[i],"��������"))
            		{
            			REWARD_D->riddle_done(pro_team[i],"��������",50,1);
            		}
            		
            		if (QUESTS_D->verify_quest(pro_team[i],"��������")){
            			num = query_temp("bandit/bandit");
				    	num2 = query_temp("bandit/hurt");
				    	total = num*50-20*num2-5;
				    	if (total<0) total=0;
    					if (num > 40) num=40;
    					if (total>2000) total=2000;
    					tell_object(pro_team[i],CYN"
�����͵������˻���˵�����˶�ʮ����ƽ·��ʮ����ɽ·��Сë��һ������"+ chinese_number(num)+"�����ѵð���"+(50*num)+"
������������������"+chinese_number(num2)+"�����ϰ�ҩ��ȥ"+(20*num2)+"������ţ��ɿ�ȥ������ʣ��������"+ chinese_number(total)+ "
����ֱ�ӻ���"+ pro_team[i]->name(1)+"���Ϲ��˺ţ�\n"NOR,this_object());
        				pro_team[i]->add("deposit",total*100);
        				if (pro_team[i]->query("quest/quest")=="��������") {
        					pro_team[i]->add("quest/difficulty",(num-2)*20);
//        					tell_object(pro_team[i],"difficulty is" + pro_team[i]->query("quest/difficulty")+"\n");
        				}
        					
        			}	
        		}
	        	for (i=0;i<sizeof(pro_team);i++){
	        		if (!objectp(pro_team[i])) continue;	
					QUESTS_D->special_reward(pro_team[i],"��������");
        		}
        	}
   	 	}
		inv=all_inventory(environment());
    	for (i=0;i<sizeof(inv);i++)
        if (inv[i]->query_temp("protecting")== this_object() && !userp(inv[i]))
           	destruct(inv[i]);
		del_marks_giver();		
    	    		
    	;

    	destruct(this_object());
    	return;
}

void del_marks_giver()
{
		object room, giver;
		room = find_object(AREA_BIANCHENG"teashop");
	
		giver = present ("fatman", room);
	
		if(giver && !userp(giver))
        	giver->delete("marks/gived");
}


void go_now()
{
    call_out("go",10);
}