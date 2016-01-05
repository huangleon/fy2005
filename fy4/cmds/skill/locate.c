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
        if(!str) return notify_fail("Ö¸Áî¸ñÊ½: locate <ÎïÆ·>\n");
	if(me->query("sen") < 10) return notify_fail("ÄãµÄÐÄÉñ²»×ãÒÔ²éÑ°Î»ÖÃ¡£\n");
	if (uptime()<120 && !wizardp(me))
		return notify_fail("·çÔÆÏµÍ³ÕýÔÚ³õÊ¼»¯£¬ÇëµÈºòÁ½·ÖÖÓ¡£\n");
	me->receive_damage("sen",5);

	if (str == "quest")
	{
		output = locate_quest(me);
		if(output=="")
			return notify_fail("È·¶¨²»ÁË"+str+"µÄ´ó¸ÅÎ»ÖÃ¡£\n");
		write(output);
		return 1;
	}
	
	if (str == "monster nian")
	{
		return notify_fail("»î¶¯NPCÎÞ·¨È·ÈÏÎ»ÖÃ¡£\n");
		return 1;
	}

	output = locate_obj(me,str);

//	if(output=="")
//		output = QUESTNPC_D->locate_obj(me,str);
	if(output=="")
		return notify_fail("È·¶¨²»ÁË"+str+"µÄ´ó¸ÅÎ»ÖÃ¡£\n");
	write(output);
	return 1;
}

string locate_quest(object me)
{
	string *distance = ({
		"¼«½ü", "ºÜ½ü", "±È½Ï½ü", "²»Ô¶",
		"²»½ü", "±È½ÏÔ¶", "ºÜÔ¶", "¼«Ô¶"
	});
	string *altitude =({
		"¸ß´¦", "µØ·½", "µÍ´¦"
	});
	string *directions=({
		"ÖÜÎ§","±±·½", "ÄÏ·½", "¶«·½","Î÷·½",
		"¶«±±·½","Î÷±±·½","¶«ÄÏ·½","Î÷ÄÏ·½"
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
		return "Íõ·çÃ»ÈÃÄãÕÒ¶«Î÷°¡¡£\n";

	item=me->query("annie_questx/mail");
	if (!item)
		return "Õâ¶«Î÷ÒÑ¾­ÕÒ²»µ½ÁË£®£®£®\n";
	
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
				output = "¡º"+item->query("name")+"¡»ËÆºõÔÚ"+dir+dis+"µÄ"+alt+"¡£\n";
				return output;

	return "";
}

string locate_obj(object me,string strr) {
	string *distance = ({
		"¼«½ü", "ºÜ½ü", "±È½Ï½ü", "²»Ô¶",
		"²»½ü", "±È½ÏÔ¶", "ºÜÔ¶", "¼«Ô¶"
	});
	string *altitude =({
		"¸ß´¦", "µØ·½", "µÍ´¦"
	});
	string *directions=({
		"ÖÜÎ§","±±·½", "ÄÏ·½", "¶«·½","Î÷·½",
		"¶«±±·½","Î÷±±·½","¶«ÄÏ·½","Î÷ÄÏ·½"
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
				if(domain1!=domain2)//Èç¹ûÔÚÍ¬Ò»¸öÇøÓò¾ÍÊ¡ÁË
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
				output = "¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+dir+dis+"µÄ"+alt+"¡£\n";
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
			tell_object(this_player(),"È·¶¨ËûÈËµÄËùÔÚÐèÒªµÈ¼¶£µ¡£\n");
			return"";
		}		
		tmpobj = find_player(strr);
		if(!tmpobj) tmpobj = find_living(strr);
		if(!tmpobj) return "";

		if (!wizardp(me) 
			&& me->query("combat_exp")* 2 < tmpobj->query("combat_exp"))
		{	
			tell_object(me,"ÄãµÄ¾­ÑéµÈ¼¶²»×ãÒÔÈ·¶¨´ËÈËµÄ¾ßÌåÎ»ÖÃ¡£\n");
			return"";
		}

		if (userp(tmpobj) && !wizardp(me))
		{
			tell_object(me, "ÄãÎÞ·¨²éÑ°Íæ¼ÒµÄ¾ßÌåÎ»ÖÃ¡£\n");
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
			if(domain1!=domain2)//Èç¹ûÔÚÍ¬Ò»¸öÇøÓò¾ÍÊ¡ÁË
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
			
//	ÈÌÊõµÄ¶ÝÐÎÖ®ÊõÊ¹Äã²»ÔÙ±»×¼È·µØlocate¡£For wizards, well, you can always use "where"¡£			
			if (tmpobj->query_temp("ninjitsu/chameleon")==2)
				output = "¡º"+tmpobj->query("name")+"¡»ËÆºõÔÚ"+dir+"¡£\n";
			else if (tmpobj->query_temp("ninjitsu/chameleon")==1)
				output = "¡º"+tmpobj->query("name")+"¡»ËÆºõÔÚ"+dir+"µÄ"+alt+"¡£\n";
			else
				output = "¡º"+tmpobj->query("name")+"¡»ËÆºõÔÚ"+dir+dis+"µÄ"+alt+"¡£\n";
					
			return output;
		}
		else return "";
	}
	else
 		return "Äã²»ÊÇ³¯Í¢¹ÙÔ±£¬²»ÄÜlocate¡£\n";

}



int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	locate <ÎïÆ·>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÊÇÓÃÀ´µÃÖªÊ¹ÃüÎïÆ·µÄ´ó¸ÅÎ»ÖÃ£¬Ã¿´ÎÊ¹ÓÃ»áÏûºÄ5µãÐÄÉñ¡£
³¯Í¢¹ÙÔ±»¹¿ÉÒÔÓÃ´ËÖ¸Áî²éÑ°ÓÎÏ·ÈËÎïµÄ´ó¸ÅÎ»ÖÃ¡£
£¨×¢Òâ£¬ÄãÖ»ÄÜ²éÑ°µ½²»³¬¹ý×ÔÉí¾­ÑéÖµÁ½±¶µÄ·ÇÍæ¼ÒÈËÎï£©

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

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
               ( £®£®)        

               (_____)~£®      
   
¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 10.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/




