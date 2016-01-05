/* 	pkd 		by silencer@fy4 03/08/2003	

	�����ػ�����PK��һϵ�к�����
	һ����PK�Ŀ���ֻ�ܷŵ�����ĵط����ػ��޷��������ߵ���ҡ�
	�й��ļ� /adm/daemons/combatd, /adm/daemons/updated
		/d/jinan/npc/butou1, /d/jinan/npc/shiye1
	��Ҫע���������̫��Ӱ��login�ٶȻ�ĳЩ��flood����
	
*/

#include <ansi.h>
inherit F_DBASE;

#define PK_LIST 	"/adm/etc/pk_list"		//	��ǰͨ����¼
#define PK_OLD_LIST 	"/adm/etc/pk_expired_list"	//	��ʷͨ����¼
#define HUNTER_LIST 		"/adm/etc/hunter_list"		//	Ѳ����¼
#define MAX_LIST	50				//	���������������


mapping *read_table(string file);			//	��ȡ
int save_table(string filename, mapping *data);		//	�洢
int add_member(string filename, mapping member);	//	�����Ա
int remove_member(string filename, string name);	//	ȥ����Ա
int count_member(string filename);			//	����������

mapping check_list(string player, string flag);		//	�����¼������ֵΪ��¼

int refresh_pk_list(int expiration);			// 	
int refresh_old_pk_list(int expiration);		//	
int refresh_hunter_list(int expiration);		//	
void update_list();					//	ÿСʱUPDATE��ȥ��ԭ�й�ʱ��¼

void print_hunter_list();
void print_pk_list();
void print_old_list();

void add_reward(string name);				// 	���Ӽ�����Ŀ

mapping *pk_list;					//	��ǰͨ����¼
mapping *pk_old_list;					//	��ʷͨ����¼
mapping *hunter;					//	Ѳ����¼
mapping field = allocate_mapping(3);
mapping format = allocate_mapping(3);

void create()
{
        seteuid(getuid());
    
        set("id","pkd");
        pk_list=read_table(PK_LIST);
        pk_old_list= read_table(PK_OLD_LIST);     
        hunter = read_table(HUNTER_LIST);
        
        print_hunter_list();
        print_pk_list();
        
	refresh_pk_list(86400);
        refresh_old_pk_list(86400*5);
        refresh_hunter_list(86400*7);
 	call_out("update_list",3600);
}

void	update_list(){			
	remove_call_out("update_list");
	refresh_old_pk_list(86400*5);	//ÿ�������һ��PK��ʷ
	refresh_pk_list(86400);		//ÿ�����һ��ͨ������
	refresh_hunter_list(86400*7);	//ÿ�������һ��Ѳ������
	call_out("update_list",3600);
}


//	OK,�������ǰ�ͨ����ʱ����Ҵ�List��ȥ����
//	�����ʱ���ߣ���ô�����ָ̻�NO_PK״̬��
//	��������ߣ���Ȼ��list��ȥ������Ҫд��һ���ļ�����updated��������

int refresh_pk_list(int expiration)
{
        int i;
        object player;
        if (!sizeof(pk_list)) return 0;
        for (i=0; i<sizeof(pk_list); i++) {
		if (pk_list[i]["start_time"]+ expiration < time()) {
			if (objectp(player=find_living(pk_list[i]["hunted"]))) {
				player->set("NO_PK",1);
				tell_object(player,WHT"�����ͨ�����ڽ����ˡ�\n"NOR);
			}	
			add_member("PK_OLD_LIST",pk_list[i]);
			pk_list -= ({ pk_list[i] });	
		}
		}       
		save_table(PK_LIST,pk_list);
		return 1;
}

int refresh_old_pk_list(int expiration)
{
        int i;
        if (!sizeof(pk_old_list)) return 0;
        for (i=0; i<sizeof(pk_old_list); i++) {
		if (!pk_old_list[i] || pk_old_list[i]["start_time"]+ expiration < time())
			pk_old_list -= ({ pk_old_list[i] });	
	}       
	save_table(PK_OLD_LIST,pk_old_list);
	return 1;
}


int refresh_hunter_list(int expiration)
{
        int i;
        object player;
        if (!sizeof(hunter)) return 0;
        for (i=0; i<sizeof(hunter); i++) {
		if (hunter[i]["join_time"]+ expiration < time()) {
			if (objectp(player=find_living(hunter[i]["id"]))) {
				player->set("NO_PK",1);
				tell_object(player,WHT"���Ѳ�������������Զ������ɱ״̬��\n"NOR);
			}	
			hunter -= ({ hunter[i] });	
		}
	}       
	save_table(HUNTER_LIST,hunter);
	return 1;
}


mapping *read_table(string filename)
{
        string *line;
        mapping *data;
        int i, rn, fn;
        string *field_1, *format_1;
        write(sprintf("file is %s\n",filename));
        line = explode(read_file(filename), "\n");
        data = ({});
        // For some reason, the first line in some file format gives error
        // So let's just do it from 2nd line.
        for(i=1; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
//        	write(sprintf("line[%d]= %O\n field=%O\n format= %O \n",i,line[i],field_1,format_1));
//          write("i =="+ i + "\n");
                if( !pointerp(field_1) ) {
                        field[filename] = line[i];
                        field_1 = explode( line[i], ":" );
//                      write("i =="+ i + " field line == "+line[i]+" \n");
                        continue;
                }
                if( !pointerp(format_1) ) {
                        format[filename]= line[i];
                        format_1 = explode( line[i], ":" );
//                      write("i =="+ i + " field line == "+line[i]+" \n");
	                continue;
                }
                break;
        }
//        write(sprintf("field=%O\n format= %O \n",field_1,format_1));
        i++;
        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field_1)) });
                sscanf( line[i], format_1[fn], data[rn][field_1[fn]] );
                fn = (++fn) % sizeof(field_1);
                if( !fn ) ++rn;
        }
        
//     	print_table(data);
        return data;
}




int save_table(string filename, mapping *data) {
	int i, j, num;
	string comment;
	string *field_2;
	
	switch (filename) {
		case PK_OLD_LIST:
		case PK_LIST:	comment = "
#  by Silencer@fy4 3/6/2003
#  The two lines defines the data format
#
#  field1:field2:field3....
#  format1:format2:format3....
#
#  hunted: ͨ���� id
#  name:  ͨ��������		
#  start_time:  ��ʼͨ��ʱ��
#  reward: ����
#  initializer ������\n\n"; break;
		case HUNTER_LIST: comment = "
#  by Silencer@fy4 3/6/2003
#  The two lines defines the data format
#
#  field1:field2:field3....
#  format1:format2:format3....
#
#  name:  Ѳ������ 
#  id:    Ѳ�� id		
#  join_time:  ����Ѳ������
#  rewarded:   �����ɹ�����\n\n"; break;
	}

	comment = comment + field[filename]+"\n";
	comment = comment + format[filename]+"\n\n";
	
	field_2 = explode( field[filename], ":" );	
	if( !write_file(filename, comment,1))
		return 0;
	
	for (i=0;i<sizeof(data);i++) {
		for (j=0;j<sizeof(field_2);j++) 
			if (!write_file(filename,(string)(data[i][field_2[j]])+"\n"))
				return 0;
		write_file(filename,"\n");
	}
	return 1;
}


int add_member(string filename, mapping member) {
	int i;
	object player;
	string msg;
	if (filename == "PK_LIST") {
		if (sizeof(pk_list) >= MAX_LIST)	return 0;
		for (i=0;i<sizeof(pk_list);i++) {
			if (pk_list[i]["hunted"] == member["hunted"])
				return 0;
		} 
		pk_list += ({member});
		if (objectp(player=find_living(member["hunted"]))) {
			player->set("NO_PK",0);
			player->set("pk_start",time());	
			tell_object(player,HIR"������������������������������������������\n"
					"�ٸ�������"+pk_list[i]["reward"]+"���ƽ�׽���㣬"
					"�䵱Ѳ������ҿ��Զ���׷ɱ��ͨ��ʱ�佫������ʮ��Сʱ��
������������������������������������������\n"NOR);
			switch (random(9)) {
				case 8: msg = "�����Ϲ�Ǯׯ�ٰ���"; break;
				case 7: msg = "ɱ��Խ����"; break;
				case 6: msg = "������࣬"; break;
				case 5: msg = "����ǧ��¥������"; break;
				case 4: msg = "����ı����"; break;
				case 3:	msg = "�����ذ���"; break;
				case 2: msg = "ͼı���ң�"; break;
				case 1: msg = "η��Ǳ�ӣ�"; break;
				default:msg = "��Ī�����";
			}
				
			CHANNEL_D->do_sys_channel(
				"info",sprintf("%s(%s)"+msg+"���ƹٸ���ʼͨ������ɱ���ۡ�", player->name(1),player->query("id")));
		}
		save_table(PK_LIST,pk_list);
		return 1;
	}
	if (filename == "PK_OLD_LIST") {
		for (i=0;i<sizeof(pk_old_list);i++) {
			if (pk_old_list[i]["hunted"] == member["hunted"])
				pk_old_list -= ({pk_old_list[i]});
		} 
		pk_old_list += ({member});
		save_table(PK_OLD_LIST,pk_old_list);
		return 1;
	}
	if (filename == "HUNTER_LIST") {
		if (sizeof(hunter)>=MAX_LIST)	return 0;
		for (i=0;i<sizeof(hunter);i++) {
			if(hunter[i]["id"] == member["id"])
				return 0;
		}
		player = find_living(member["id"]);

		CHANNEL_D->do_sys_channel("sys",sprintf("Added %s is %O",member["id"], player));
		
		if (objectp(player)) {
			hunter += ({member});
			player->set("NO_PK",0);
			player->set("pk_start",time());		// ��������Ӿ���
			tell_object(player,HIG"�����Ѿ��뽭����ɱ֮�У�����Ӻ�ͬ����ҿɶ���׷ɱ��\n"NOR);
			save_table(HUNTER_LIST,hunter);
			return 1;
		}
	}
	write(" adding member is wrong, please report to Silencer@fengyun.com \n");		
	return 0;
}


int remove_member(string filename, string name) {
	object player;
	int i;
	if (!objectp(player=find_living(name))) 
		return 0;
	if (filename == "PK_LIST") {
		for (i=0;i<sizeof(pk_list);i++) {
			if (pk_list[i]["hunted"] == name) {
				add_member("PK_OLD_LIST",pk_list[i]);
				pk_list -= ({ pk_list[i] });
				player->set("NO_PK",1);
				save_table(PK_LIST,pk_list);
				return 1;
			}
		}
	}
	if (filename == "PK_OLD_LIST") {
		for (i=0;i<sizeof(pk_old_list);i++) {
			if (pk_old_list[i]["hunted"] == name) {
				pk_old_list -= ({ pk_old_list[i] });
				save_table(PK_OLD_LIST,pk_old_list);
				return 1;
			}
		} 
	}
	if (filename == "HUNTER_LIST") {
		for (i=0;i<sizeof(hunter);i++) {
			if (hunter[i]["id"] == name) {
				hunter -= ({ hunter[i] });
				player->set("NO_PK",1);
				save_table(HUNTER_LIST,hunter);	
				return 1;
			}
		}
	}
//	write ("NONE is removed.\n");
	return 0;
}

int count_member(string filename) {
	if (filename == "PK_LIST")		return sizeof(pk_list);
	else if (filename == "PK_OLD_LIST")	return sizeof(pk_old_list);
	else if (filename == "HUNTER_LIST")		return sizeof(hunter);

	return 0;
}


mapping check_list(string player, string type){
	int i;
	
	if (type == "PK_OLD_LIST") {
		if (!sizeof(pk_old_list)) return 0;
		for (i=0; i<sizeof(pk_old_list); i++) {
			if (pk_old_list[i]["hunted"] == player)
				return pk_old_list[i];
		}
	} else if (type=="PK_LIST"){
		if (!sizeof(pk_list)) return 0;
		for (i=0; i<sizeof(pk_list); i++) 
		if (pk_list[i]["hunted"] == player)
			return pk_list[i];
	} else if (type =="HUNTER_LIST") {
		if (!sizeof(hunter)) return 0;
		for (i=0; i<sizeof(hunter); i++) 
		if (hunter[i]["id"] == player)
			return hunter[i];
	}
//	write("ILLEGAL CHECK FLAG.\n");
	return 0;
}


void print_pk_list() {
	int i, duration;
	if (!sizeof(pk_list)) {
		write("\n����û������ͨ���Ĵ�ͽ��\n");
		return;
	}
	write (HIY"\n��������������������������""ͨ������������������������������\n\n"NOR);
	write (YEL"      ���� 		ͨ��ʱ��    �ͽ�          ������\n"NOR);
	for (i=0; i<sizeof(pk_list); i++) {
		duration = ((time()-pk_list[i]["start_time"]))/60/60;
		write(sprintf("%-4d  %s��%s��  \t%dСʱ\t  %d���ƽ�\t  %s\n",
			i+1, pk_list[i]["name"],pk_list[i]["hunted"], duration, 
			pk_list[i]["reward"], pk_list[i]["initializer"]));		
	}
	write (HIY"\n����������������������������������������������������������\n"NOR);
	return;
}

void print_hunter_list() {
	int i, duration;
	if (!sizeof(hunter)) {
		write("\n����û������ִ�й����Ѳ����\n");
		return;
	}
	write (HIY"\n��������������������������""Ѳ������������������������������\n\n"NOR);
	write (YEL"      ���� 		����ʱ��	�����ɹ�����\n"NOR);
	for (i=0; i<sizeof(hunter); i++) {
		
		duration = ((time()-hunter[i]["join_time"]))/60/60;
		write(sprintf("%-4d  %s��%s�� \t%dСʱ\t\t  %d\n",
			i+1, hunter[i]["name"],hunter[i]["id"], duration, hunter[i]["rewarded"] 
			));		
	}
	write (HIY"\n����������������������������������������������������������\n"NOR);
	return;
}


void print_old_list() {
	int i, duration;
	if (!sizeof(pk_list)) {
		write("\n����û��ԭʼ��¼��\n");
		return;
	}
	write (HIY"\n����������������������""ͨ����������������������������������\n\n"NOR);
	for (i=0; i<sizeof(pk_old_list); i++) {
		duration = ((time()-pk_old_list[i]["start_time"]))/60/60;
		write(sprintf("%d��%s��%s��  ͨ��ʱ�䣺%dСʱ  ���ͣ�%d���ƽ�\n",
			i+1, pk_old_list[i]["name"],pk_old_list[i]["hunted"], duration, 
			pk_old_list[i]["reward"], pk_old_list[i]["initializer"]));		
	}
	write (HIY"\n����������������������������������������������������������\n"NOR);
	return;
}

void add_reward(string name){
	int i;
	
	for (i=0;i<sizeof(hunter);i++){
		if (hunter[i]["id"]==name) {
			hunter[i]["rewarded"]++;
			save_table(HUNTER_LIST,hunter);
			return;
		}
	}
	return;
}
