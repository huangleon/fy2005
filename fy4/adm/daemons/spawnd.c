// Silencer@fengyun workgroup	June.2005
//ϡ�й������Ʒ������
//spawnd.c:	����ϡ�й������Ʒ�Ķ�ʱ�ֲ�

//	Now it will actively search item and NPC and recreate them if necessary.
//	CLONE will not trigger Spawnd
// ע�������Ʒ��������������佫ֹͣ����Ʒ����֮��Ĳ�����
// ������д��room���������������ò�Ҫ�ù���not tested thoroughly

#define SPAWN_INTERVAL 3600 // 3600 --> 1 hour per check.��Ȼ�������3457���㻵:D

#include <ansi.h>

inherit F_DBASE;
mapping *spawn_table;
mapping *read_table(string file);

void init_spawn_table();				//����ʼ��
void show_spawn_table();				//	���������������
void clear_spawn_table();				// �� init_spawn_tableǰ�������зǣ����ĸ������

int restart_spawn(int order, int num);  // ��room/npc/item�Լ�call this����restart;
int check_spawn( int num); 				//  spawnd ���ĳ��Ʒ�Ƿ��Ѿ���player������


void create()
{
        seteuid(getuid());
        spawn_table=read_table("/adm/etc/spawn_table");
        set("channel_id", "�ֲ�����");
        set("id","spawnd");
		init_spawn_table();
}

void init_spawn_table()
{
        int i;
        clear_spawn_table();			// All previous have to be destructed.
        for(i=0;i<sizeof(spawn_table);i++)
        {
                spawn_table[i]["counter"] = -1-random(10); // reboot�����10Сʱ�ڷֲ�
                spawn_table[i]["start"] = 1;
                spawn_table[i]["respawn"] = spawn_table[i]["respawn_base"] 
                			+ random(spawn_table[i]["respawn_random"]);
        }
/*        CHANNEL_D->do_sys_channel(
                        "sys",sprintf("��ʼ���ֲ��б�\n%O\n��ʼ����ϡ�\n",
                        spawn_table));*/
        call_out("dis_spawn_table",SPAWN_INTERVAL);	
}

void show_spawn_table()
{
	CHANNEL_D->do_sys_channel(
                        "sys",sprintf("��ǰ��Ʒ�ֲ����Ϊ��\n%O\n\n",
                        spawn_table));
}

//	�������is outdated, ����ǿ��respawn��
int restart_spawn(int order, int num)	// numһ������Ϊ0�ˣ�������Ҫ��������ʼ(-1)
{
	spawn_table[order]["start"] = 1;
	spawn_table[order]["counter"] = num;	
	return 1;
}

void dis_spawn_table()
{
	int i;
	string name;
	object obj, room;
	
	for(i=0;i<sizeof(spawn_table);i++)
	{
		if (!spawn_table[i]["start"])	
		{	
			// ���ﴦ����Ʒ��NPC��respawn
			if (spawn_table[i]["type"] == "room")	continue;	
			if (check_spawn (i))	continue; // �Ѿ���һ��û��user���˵�copy
			
			spawn_table[i]["start"] = 1;
			spawn_table[i]["counter"] = 1;
		}
		spawn_table[i]["counter"]++;
		if (spawn_table[i]["counter"]>=spawn_table[i]["respawn"])
			spawn_table[i]["counter"] = 0;
		if (spawn_table[i]["counter"] == 0)	
		{
			name = spawn_table[i]["file"];
			
			CHANNEL_D->do_sys_channel(
                        "sys",sprintf("ϵͳ��%s��ʼ�ֲ�%s\n",
                        "/cmds/usr/uptime"->chinese_time(5,time()+""),name));
                        
			spawn_table[i]["start"] = 0;
			
			// Room
			if (spawn_table[i]["type"] == "room")
			{
				obj = find_object(name);
				if (!obj) obj = load_object(name);
				if (!obj) 
					spawn_table[i]["respawn"] = 100000; 				
				else
				{
					obj->set("spawn_num",i);
					obj->set("spawn_legal",1);
					obj->init_spawn();
				}	
				continue;
			}
			// ���������Ʒ
			obj = new(name);
			if (!obj)
			{
				spawn_table[i]["respawn"] = 100000;
				continue;	
			}
			obj->set("spawn_num",i);
			obj->set("spawn_legal",1);
			
			if (!spawn_table[i]["self_init"])
			{
				room = find_object(obj->query("spawn_location"));
				if (!room) room = load_object(obj->query("spawn_location"));
				if (!room || !(obj->move(room)))
				{
					spawn_table[i]["respawn"] = 100000;
					destruct(obj);
				}
				if (room) room->set("perma_exist",1);	// We don't want it to be cleaned out.
				continue;	
			}
			if (!obj->init_spawn())
				destruct(obj);	
		}
	}
	call_out("dis_spawn_table",SPAWN_INTERVAL);
}
	

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;
//      write(sprintf("file is %s\n",file));
        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
//               write(sprintf("line[%d]= %O\n field=%O\n format= %O \n",i,line[i],field,format));
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
//      write(sprintf("line= %O\n field=%O\n format= %O \n",line,field,format));
        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}


void clear_spawn_table()
{
	int i, j;
	string name;
	object *list;
	
	for(i=0;i<sizeof(spawn_table);i++)
	{
		if (spawn_table[i]["type"] == "room")	continue;

		name = spawn_table[i]["file"];			
/*		CHANNEL_D->do_sys_channel(
              "sys",sprintf("ϵͳ��%s��ʼ����%s��\n",
                     "/cmds/usr/uptime"->chinese_time(5,time()+""),name));*/
        // ���������Ʒ
		list = children (name);
		if (sizeof(list)<1) continue;
		for (j=0; j< sizeof(list); j++)
		{
			if (!list[j]->query("spawn_legal"))	continue; 	// not spawnd created.
			if (!environment(list[j]))			continue;	// source
			if (spawn_table[i]["type"] == "item")
			{
				if (userp(environment(list[j])))	continue;	// user hold
				if (environment(environment(list[j])))
				if (userp(environment(environment(list[j]))))	continue;	// user hold in container
				if (environment(list[j])->query("tax")>=1)	continue;
			}	
			CHANNEL_D->do_sys_channel(
             	"sys",sprintf("ϵͳ���%O @ %O��\n",list[j], environment(list[j])));
			destruct( list[j]);		
		}				
	}
	return;	
}

int check_spawn( int num)	{
	
	string name;
	object *list;
	int i, count=0;
		
	if (spawn_table[num]["type"] == "room")	return 0;
		
	name = spawn_table[num]["file"];
	list = children (name);
	if ( !list || sizeof (list) < 1)	return 0;
	for (i = 0; i <sizeof(list) ; i++)
	{ 
		if (!list[i]->query("spawn_legal"))	continue; 	// not spawnd created.
		if (!environment(list[i]))	continue;			// source
		if (userp(environment(list[i])))	continue;	// user hold
		if (environment(environment(list[i])))
		if (userp(environment(environment(list[i]))))	continue;	// user hold in container
		count ++;
	}
	return count;
}	
			
	