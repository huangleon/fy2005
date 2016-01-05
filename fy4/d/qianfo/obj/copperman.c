// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name( "����������ͼ��ͭ��", ({ "copperman","man"  }) );
	set("unit", "��");
	set("no_get",1);
	set("value",20);
	set("long","
����һ������������ͼ��ͭ�ˣ���ͭ�˵�[31m�ģ���������[32m��
[1;32m�Σ��������[0;32m��[33mθ����������裩[32m��[37m�Σ������磩[32m��
[34m�������������[32m�Ĳ�λ����һС�ף���ͭ�˵ĵ���֮������
���������ӡ������룩��
\n");
	set_weight(5000);
	::init_item();
}
void init()
{
	add_action("do_touch","touch");
}

int closepath()
{
        object env;
        env = environment(this_object());
        if( !env->query("exits/north") ) return 1;
        message("vision","ͭ���ֶ���������ת�ص�ԭ����λ�ӣ�����\n",env );
		env->delete("exits/north");
}
int open_path()
{
        object env;
        env = environment(this_object());
        if( !env->query("exits/north"))
        {
	        env->set("exits/north",AREA_QIANFO"tianwang");
		message("vision","ͭ���۾���Ȼ����������������¶�������İ�������\n",env);
	        call_out("closepath",5);
        }
        return 1;
}

int check_needles()
{
	object liver,kidney,stomach, heart, lung, env,*inv;
	object red,green,yellow, white,black;
	env = environment(this_object());
	if(!objectp(liver=present("liver",env))) return 0;
	if(!objectp(kidney=present("kidney",env))) return 0;
	if(!objectp(stomach=present("stomach",env))) return 0;
	if(!objectp(heart=present("heart",env))) return 0;
	if(!objectp(lung=present("lung",env))) return 0;
	
	inv = all_inventory(liver);
		if( sizeof(inv) != 1) return 0;
		green = inv[0];
		if((string)green->query("name") != "��ɫ��ϸ��" && green->query("name") != "����ɫ��ϸ��" ) return 0;
        
    inv = all_inventory(kidney);
        if( sizeof(inv) != 1) return 0;
        black = inv[0];
        if((string)black->query("name") != "��ɫ��ϸ��" && black->query("name") != "����ɫ��ϸ��") return 0;
    
    inv = all_inventory(stomach);
        if( sizeof(inv) != 1) return 0;
        yellow= inv[0];
        if((string)yellow->query("name") != "��ɫ��ϸ��" && yellow->query("name") != "����ɫ��ϸ��") return 0;
    
    inv = all_inventory(heart);
        if( sizeof(inv) != 1) return 0;
        red= inv[0];
        if((string)red->query("name") != "��ɫ��ϸ��" && red->query("name") != "����ɫ��ϸ��") return 0;
    
    inv = all_inventory(lung);
        if( sizeof(inv) != 1) return 0;
        white= inv[0];
        if((string)white->query("name") != "��ɫ��ϸ��" && white->query("name") != "����ɫ��ϸ��") return 0;
// now we have everything, let's open path! and reset this room;
		red->move(env); destruct(red);
        green->move(env); destruct(green);
        yellow->move(env); destruct(yellow);
        white->move(env); destruct(white);
        black->move(env); destruct(black);
	open_path();
	return 1;
}

int do_touch(string arg)
{
        object me,env;
        if( !arg ) return 0;
        if( arg != "��ӡ" && arg != "mark") return 0;
        me = this_player();
        if((int) me->query("force") < 50) {
        	write("���������������50����������\n"); 
            return 1;
        }
        me->add("force",-50);
        
        message_vision("$N��һ����������ͭ�����ڣ�����\n",me);
        // if there is needles 
        if(!check_needles() ) {
	        REWARD_D->riddle_done(me,"����ͭ��",10,1);		
			if(!me->query_temp("marks/copperman"))
				me->set_temp("marks/copperman",1);
			open_path();
			return 1;
		}
		
        // No needles
                
        
	// for non-xingguo players, each login only need insert needles once.
		if( me->query_temp("marks/copperman")) {
            open_path();
            return 1;
        }
        
        // for xingguo students, it needs 200 force w/o needles
        if( me->query("class")=="bonze") {
            env = environment(this_object());
            message("vision","ͭ���۾���Ȼ����������������¶�������İ�������\n",env);
			message_vision("$Nһ������˰�����ͭ����$N����ֺ����ˡ�\n",me);
			me->move("/d/qianfo/tianwang");
            return 1;
        }

        message_vision("��$N�����ѽߵ�˲�䣬ͭ���۾��ƺ���Ҫ��������\n",me);
        return 1;
}
