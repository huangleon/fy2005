#include <combat.h>
#include <ansi.h>
#define SYNTAX	"ָ���ʽ��gq <dir>\n"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int i,j,k,m,flag=0;
	string *top = ({"/d/","/u/","/p/"});
	string direc,*dir, roomname;
	string *file;
	string status;
	object *nodes = ({});
	object newnode;
	object room;
        if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
	seteuid(getuid());
        for(i=0; i<sizeof(top); i++) 
	{
	dir = get_dir(top[i]);
	write(top[i]+"\n");
        for(j=0; j<sizeof(dir); j++)
	{
        write(top[i]+dir[j]+"/"+"\n");
	file = get_dir(top[i]+dir[j]+"/");
        for(k=0; k<sizeof(file); k++)
	{
        if( sscanf(file[k],"%s.c", roomname) != 1) continue;
		write( "working on:" +file[k]+"\n");
	reset_eval_cost();
		room = load_object(top[i]+dir[j]+"/"+file[k]);
	
	flag = 0;
	for(m=0;m<sizeof(nodes);m++)
		{
			if(nodes[m]->query("x") == room->query("coor/x")
			&& nodes[m]->query("y") == room->query("coor/y")
			&& nodes[m]->query("z") == room->query("coor/z"))
			{
			flag = 1;
			nodes[m]->add("dups"," "+top[i]+dir[j]+"/"+file[k]);
			}					

		}
	if(!flag)
		{
		newnode = new("/obj/armor/cloth.c");
		newnode->set("x",room->query("coor/x"));
                newnode->set("y",room->query("coor/y"));
                newnode->set("z",room->query("coor/z"));
		newnode->set("dups",top[i]+dir[j]+"/"+file[k]);
		nodes += ({ newnode });
		}
	
	}}}
	for(i=0;i<sizeof(nodes);i++)
	{
	if(strsrch(nodes[i]->query("dups")," ") != -1)
	write_file("DUP",nodes[i]->query("dups")+"\n");
	}

	return 1;
}
