// by Tie@fy3 hehe
//	inherit F_CLEAN_UP;
inherit F_DBASE;
string locate_obj(object me,string strr);
string locate_quest(object me);
object find_env(object ob);
mapping *read_table(string file);
mapping *quests;

#define MAX_DIS	7
#define MAX_ALT  2
#define MAX_DIR  8

mapping *read_table(string file) {
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
int main(object me, string str)
{
	string output = "";
        if(!str) return notify_fail("ָ���ʽ: locate <��Ʒ>\n");
	if(me->query("sen") < 10) return notify_fail("����������Բ�Ѱλ�á�\n");
	if (uptime()<120 && !wizardp(me))
		return notify_fail("����ϵͳ���ڳ�ʼ������Ⱥ������ӡ�\n");
	me->receive_damage("sen",5);

	if (str == "quest")
	{
		output = locate_quest(me);
		if(output=="")
			return notify_fail("ȷ������"+str+"�Ĵ��λ�á�\n");
		write(output);
		return 1;
	}
	
	if (str == "monster nian")
	{
		return notify_fail("�NPC�޷�ȷ��λ�á�\n");
		return 1;
	}

	output = locate_obj(me,str);

//	if(output=="")
//		output = QUESTNPC_D->locate_obj(me,str);
	if(output=="")
		return notify_fail("ȷ������"+str+"�Ĵ��λ�á�\n");
	write(output);
	return 1;
}

string locate_quest(object me)
{
	string *distance = ({
		"����", "�ܽ�", "�ȽϽ�", "��Զ",
		"����", "�Ƚ�Զ", "��Զ", "��Զ"
	});
	string *altitude =({
		"�ߴ�", "�ط�", "�ʹ�"
	});
	string *directions=({
		"��Χ","����", "�Ϸ�", "����","����",
		"������","������","���Ϸ�","���Ϸ�"
	});
	object ob, tmpobj,where, *ob_list;
	object item,room;
	string domain1,domain2;
	string output,dis,alt,dir;
	int i;
	int x,y,z,x0,y0,z0;
	int realdis;
	int tmp;
	string str="";

	if (!me->query("annie_questx/index"))
		return "����û�����Ҷ�������\n";

	item=me->query("annie_questx/mail");
	if (!item)
		return "�ⶫ���Ѿ��Ҳ����ˣ�����\n";
	
	ob = find_env(item);

	reset_eval_cost();

		room = environment(me);



				sscanf(file_name(room), "/d/%s/%*s", domain1);
				sscanf(file_name(ob), "/d/%s/%*s", domain2);
				x0= (int)room->query("coor/x");
				y0= (int)room->query("coor/y");
				z0= (int)room->query("coor/z");

				if (domain1 == domain2) {
					x=(int)ob->query("coor/x")-x0;
					y=(int)ob->query("coor/y")-y0;
					z=(int)ob->query("coor/z")-z0;
				} else {
					x=ob->query("coor/x") / COOR_D->query_ratio(domain2)-
						x0 / COOR_D->query_ratio(domain1);
					y=ob->query("coor/y") /  COOR_D->query_ratio(domain2)-
						y0 /  COOR_D->query_ratio(domain1);
					z=ob->query("coor/z") /  COOR_D->query_ratio(domain2)-
						z0 / COOR_D->query_ratio(domain1);
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				}
				realdis=0;
				if(x<0)realdis-=x; else realdis+=x;
				if(y<0)realdis-=y; else realdis+=y;
				if(z<0)realdis-=z; else realdis+=z;
				tmp =(int)  realdis/50;
				if(tmp>MAX_DIS) tmp = MAX_DIS;
				dis=distance[tmp];
				if(z>0) alt=altitude[0];
				if(z<0) alt=altitude[2];
				if(z==0) alt=altitude[1];
				if(x==0&&y==0) dir=directions[0];
				if(x==0&&y>0) dir=directions[1];
				if(x==0&&y<0) dir=directions[2];
				if(x>0&&y==0) dir=directions[3];
				if(x<0&&y==0) dir=directions[4];
				if(x>0&&y>0) dir=directions[5];
				if(x<0&&y>0) dir=directions[6];
				if(x>0&&y<0) dir=directions[7];
				if(x<0&&y<0) dir=directions[8];
				output = "��"+item->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
				return output;

	return "";
}

string locate_obj(object me,string strr) {
	string *distance = ({
		"����", "�ܽ�", "�ȽϽ�", "��Զ",
		"����", "�Ƚ�Զ", "��Զ", "��Զ"
	});
	string *altitude =({
		"�ߴ�", "�ط�", "�ʹ�"
	});
	string *directions=({
		"��Χ","����", "�Ϸ�", "����","����",
		"������","������","���Ϸ�","���Ϸ�"
	});
	object ob, tmpobj,where, *ob_list;
	object item,room;
	string domain1,domain2;
	string output,dis,alt,dir;
	int i;
	int x,y,z,x0,y0,z0;
	int realdis;
	int tmp;
	string str="";
	reset_eval_cost();

	seteuid(getuid());
	quests=read_table("/quest/dynamic_quest");
	
	for( i=0; i < sizeof(quests); i++)
	{
		if(!objectp(item= find_object(quests[i]["file_name"])))
			item = load_object(quests[i]["file_name"]);
		if (!item)	
			write("Please Report: Missing quest is "+ quests[i]["file_name"]+"\n");
		else
			if(item->query("id") == strr || item->query("name") == strr) 
				str = quests[i]["file_name"];
	}
	// tell_object(me, str);
	if(str != "") {
		room = environment(me);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			ob=find_env(ob_list[i]);
			if(ob)
			{	
		        	sscanf(file_name(room), "/d/%s/%*s", domain1);
		        	sscanf(file_name(ob), "/d/%s/%*s", domain2);
				x0= (int)room->query("coor/x");
				y0= (int)room->query("coor/y");
				z0= (int)room->query("coor/z");
			/*	x=(int)ob->query("coor/x")-x0;
				y=(int)ob->query("coor/y")-y0;
				z=(int)ob->query("coor/z")-z0;
				if(domain1!=domain2)//�����ͬһ�������ʡ��
				{
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				} */
				if (domain1 == domain2) {
					x=(int)ob->query("coor/x")-x0;
					y=(int)ob->query("coor/y")-y0;
					z=(int)ob->query("coor/z")-z0;
				} else {
					x=ob->query("coor/x") / COOR_D->query_ratio(domain2)-
						x0 / COOR_D->query_ratio(domain1);
					y=ob->query("coor/y") /  COOR_D->query_ratio(domain2)-
						y0 /  COOR_D->query_ratio(domain1);
					z=ob->query("coor/z") /  COOR_D->query_ratio(domain2)-
						z0 / COOR_D->query_ratio(domain1);
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				}
				realdis=0;
				if(x<0)realdis-=x; else realdis+=x;
				if(y<0)realdis-=y; else realdis+=y;
				if(z<0)realdis-=z; else realdis+=z;
				tmp =(int)  realdis/50;
				if(tmp>MAX_DIS) tmp = MAX_DIS;
				dis=distance[tmp];
				if(z>0) alt=altitude[0];
				if(z<0) alt=altitude[2];
				if(z==0) alt=altitude[1];
				if(x==0&&y==0) dir=directions[0];
				if(x==0&&y>0) dir=directions[1];
				if(x==0&&y<0) dir=directions[2];
				if(x>0&&y==0) dir=directions[3];
				if(x<0&&y==0) dir=directions[4];
				if(x>0&&y>0) dir=directions[5];
				if(x<0&&y>0) dir=directions[6];
				if(x>0&&y<0) dir=directions[7];
				if(x<0&&y<0) dir=directions[8];
				output = "��"+ob_list[i]->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
				return output;
			}
			else return "";
		}
	}
	else 
	if(wizardp(me) || me->query("class") == "official")
	{
		if (!wizardp(me) && me->query("combat_exp")<50000)
		{
			tell_object(this_player(),"ȷ�����˵�������Ҫ�ȼ�����\n");
			return"";
		}		
		tmpobj = find_player(strr);
		if(!tmpobj) tmpobj = find_living(strr);
		if(!tmpobj) return "";

		if (!wizardp(me) 
			&& me->query("combat_exp")* 2 < tmpobj->query("combat_exp"))
		{	
			tell_object(me,"��ľ���ȼ�������ȷ�����˵ľ���λ�á�\n");
			return"";
		}

		if (userp(tmpobj) && !wizardp(me))
		{
			tell_object(me, "���޷���Ѱ��ҵľ���λ�á�\n");
			return "";
		}	
		
			
			
		ob = find_env(tmpobj);
		room = environment(me);
		if(ob)
		{
			sscanf(file_name(room), "/d/%s/%*s", domain1);
	        	sscanf(file_name(ob), "/d/%s/%*s", domain2);
			x0= (int)room->query("coor/x");
			y0= (int)room->query("coor/y");
			z0= (int)room->query("coor/z");
	/*		x=(int)ob->query("coor/x")-x0;
			y=(int)ob->query("coor/y")-y0;
			z=(int)ob->query("coor/z")-z0;
			if(domain1!=domain2)//�����ͬһ�������ʡ��
			{
				x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
				y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
				z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
			}*/
			if (domain1 == domain2) {
				x=(int)ob->query("coor/x")-x0;
				y=(int)ob->query("coor/y")-y0;
				z=(int)ob->query("coor/z")-z0;
			} else {
				x=ob->query("coor/x") / COOR_D->query_ratio(domain2)-
					x0 / COOR_D->query_ratio(domain1);
				y=ob->query("coor/y") /  COOR_D->query_ratio(domain2)-
					y0 /  COOR_D->query_ratio(domain1);
				z=ob->query("coor/z") /  COOR_D->query_ratio(domain2)-
					z0 / COOR_D->query_ratio(domain1);
				x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
				y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
				z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
			}
			realdis=0;
			if(x<0)realdis-=x; else realdis+=x;
			if(y<0)realdis-=y; else realdis+=y;
			if(z<0)realdis-=z; else realdis+=z;
			tmp =(int)  realdis/50;
			if(tmp>MAX_DIS) tmp = MAX_DIS;
			dis=distance[tmp];
			if(z>0) alt=altitude[0];
			if(z<0) alt=altitude[2];
			if(z==0) alt=altitude[1];
			if(x==0&&y==0) dir=directions[0];
			if(x==0&&y>0) dir=directions[1];
			if(x==0&&y<0) dir=directions[2];
			if(x>0&&y==0) dir=directions[3];
			if(x<0&&y==0) dir=directions[4];
			if(x>0&&y>0) dir=directions[5];
			if(x<0&&y>0) dir=directions[6];
			if(x>0&&y<0) dir=directions[7];
			if(x<0&&y<0) dir=directions[8];
			
//	�����Ķ���֮��ʹ�㲻�ٱ�׼ȷ��locate��For wizards, well, you can always use "where"��			
			if (tmpobj->query_temp("ninjitsu/chameleon")==2)
				output = "��"+tmpobj->query("name")+"���ƺ���"+dir+"��\n";
			else if (tmpobj->query_temp("ninjitsu/chameleon")==1)
				output = "��"+tmpobj->query("name")+"���ƺ���"+dir+"��"+alt+"��\n";
			else
				output = "��"+tmpobj->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
					
			return output;
		}
		else return "";
	}
	else
 		return "�㲻�ǳ�͢��Ա������locate��\n";

}



int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	locate <��Ʒ>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ����������֪ʹ����Ʒ�Ĵ��λ�ã�ÿ��ʹ�û�����5������
��͢��Ա�������ô�ָ���Ѱ��Ϸ����Ĵ��λ�á�
��ע�⣬��ֻ�ܲ�Ѱ��������������ֵ�����ķ�������

[0;1;37m����������������������������������������������������������������[0m   

HELP
	);
	return 1;
}

object find_env(object ob)
{
	while(ob)
	{
	if(ob->query("coor") ) return ob;
	else ob=environment(ob);	
	}
	return ob;
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/




