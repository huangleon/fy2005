#include <ansi.h>

int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, int flag,string dir,int gold_cost,int s_cost,int space, int w, string text);
string get_free_dir();

inherit ROOM;

int init()
{
	add_action("do_buildroom","build");
}

string get_free_dir()
{
	string *direc= ({"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17"});
	int i;
	for (i=0;i<sizeof(direc);i++ )
		if (!query("exits/"+query("floor")+direc[i]))
			return query("floor")+direc[i];
	return 0;
}

int do_buildroom(string arg)
{
	int flag,gold_cost,s_cost;
	string stitle;
	string ltitle;
	string dir;
	object env;
	object gold;
	int w;
	int space;
	object me = this_player();
    seteuid(getuid());
		
//	if (me->query("created_mainroom"))
//		return notify_fail("���Ѿ������һ�������ˡ�\n");

	if (!arg){
		write("\n�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
		write(HIR"
		���Ƴǽ��ݼ۸�һ����"NOR+YEL"

 �ռ䡡����ϼ۸�	 �����ͣ�����	 �½��ܣ� 
 1������ 150g/120pj��	10g/20pj 	��1.4g/1pj��		�� 
 2������ 300g/240pj��	20g/40pj 	  2.8g/2pj���� 
 3������ 600g/380pj��	40g/80pj 	  5.6g/3pj���� 
 4������1200g/560pj ��	80g/160pj 	  11.2g/4pj�� 
 5������2400g/820pj ��	160g/320pj	  22.4g/5pj��  
\n"NOR);		
		write("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
		return 1;
	}	
			
    if(me->query("created_room") >= 1)
		return notify_fail("Ŀǰ����ÿ����ֻ����һ�䷿��\n");
	
    if (me->query("combat_exp")< 100000)
		return notify_fail("�ɲ������ʲô�˶����ڷ��Ƴ��ｨ���ģ����ٵõȼ�ʮ���ϲ��С�\n");
		
    if(sscanf(arg,"%s %d %d %d",stitle,flag,space,w) != 4)
		return notify_fail("ָ���ʽ����build [����] [����] [�ռ�] [֧��]	\n");
	
	dir=get_free_dir();
	if (!dir)
		return notify_fail("�����Ѿ�û�п����ӿ���ס�ˡ�\n");
			
	switch (space)
	{	// lazy . annie
		case 1:
			gold_cost = 10;
			break;
		case 2:
			gold_cost = 20;
			break;
		case 3:
			gold_cost = 40;
			break;
		case 4:
			gold_cost = 80;
			break;
		case 5:
			gold_cost = 160;
			break;	
		default:
			return notify_fail("�ռ�ֻ��Ϊ��������\n");
	}

	if (me->query("created_room") == 1)
		gold_cost *= 2;
	else if (me->query("created_room") == 2)
		gold_cost *= 4;
	else if (me->query("created_room") == 0)
		gold_cost *= 1;
	else 
		gold_cost *= 100;	// bug.
	
	if (w != 0 && w != 1)
		if(!gold) return notify_fail("֧��ֻ��Ϊ����������˰���򣱣�һ����ϣ���\n");

	if (w==1)
	{
		s_cost = gold_cost*2;
		gold_cost = gold_cost*15;
		s_cost = s_cost+space*100;
	}
	else
		s_cost=gold_cost*2;

	gold = present("gold_money",me);
		if(!gold) return notify_fail("������û�н��ӡ�\n");

	if(gold->query_amount() < gold_cost)
       	return notify_fail("������û��"+chinese_number(gold_cost)+"�����ӡ�\n");

	if(me->query("score") < s_cost)
       	return notify_fail("������۲���"+chinese_number(s_cost)+"�㣡\n");

    env = environment(me);
	if(check_legal_name(stitle))
		 me->edit( (: enter_desc , me,gold, stitle, flag, dir,gold_cost,s_cost,space,w :) );
	return 1;
	
}

void enter_desc(object me,object gold, string s_title, int flag,string dir,int gold_cost,int s_cost,int space, int w, string text)
{
	int i;
	int okey=0;
	object env;
	if(!check_legal_long(text)) return;

	// double checks here because of the delay in enter_desc.
	if(query("exits/"+dir))
	{
		tell_object(me,"��������Ѿ��з����ˣ�\n");
		return;
	}
	if (gold->query_amount() < gold_cost)
	{
		tell_object(me,"���Ǯ������\n");
		return;
	}
	if(me->query("score") < s_cost) {
       	tell_object(me,"������۲���"+chinese_number(s_cost)+"�㣡\n");
		return;
	}

	BR_D->buildroom(me,gold,flag,s_title,text,dir,1,gold_cost,s_cost,space,w);

}


int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_long(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 120) || (strlen(name) > 600 ) ) {
                write("�Բ�������������������ʮ�����ٸ������֡�"+strlen(name)+"\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("�Բ����������������ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ����������������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

