#include <ansi.h>
inherit ROOM;

string 	*ebook = ({" "});
string show_list();
int read_book(string arg);

// 	��ʱ����Ҫ�Ķ�code�������鼮

string *book_bai = explode(read_file("/doc/help/book/book_bai"), "Page");

void create()
{
    set("short", "��¥");
    set("long", @LONG
��¥�Ǿ�������ղء�װ���鼮�ĵط��������������һ�ŷ��ż��ų��ų߿�
��ߵ�[37m��ľ��[32m��ÿ������ǰ���������������æµ��һ�Ե�����϶ѻ���ɽ���Ǹ�
װ���û�δ���е��鼮������ɢ���ŵ�������ī���㡣
LONG
    );
    set("exits", ([
	"down" : __DIR__"jssju1",
	"up": __DIR__"jssju3",
      ]));

    set("item_desc", ([
		"��ľ��": (: show_list() :),
		"���":	(: show_list() :),
		"shelf": (: show_list() :),
		"table": (: show_list() :),
    ]));

    set("objects", ([
	
    ]) );
	
    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",20);
    set("map","fynorth");
    setup();
}


string	show_list()	{
    write("���һ�ŷ���������³������װ�鼮����list���Բ鿴Ŀ¼��    
������뿴�Ļ���������read���read 1�������Ķ���һ����\n");
	return "";
}

void 	init(){
	add_action("do_read","read");
	add_action("do_list", "list");
}


string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR
});

string skill_level(int level)
{
	int grade;

	grade = level / 10;

	if( grade >= sizeof(knowledge_level_desc) )
		grade = sizeof(knowledge_level_desc)-1;
	return knowledge_level_desc[grade];

}

int	do_read(string arg){
	mapping *data;
	mapping tianjiao;
	string msg,*list,file;
	int i, j, num;
	
	if (this_player()->query_temp("timer/read_book")+1>time())
	{
		tell_object(this_player(),"��������һ��һ������\n");
		return 1;
	}
	this_player()->set_temp("timer/read_book",time());
	
	if (arg == "1"){
		data = STATUS_D->query_exp_list();
		num = sizeof(data);
		msg = HIR"	���Ƹ������а�ǰ"+ chinese_number(num)+"��\n"NOR;
		msg += CYN"=========================================\n"NOR;
		msg += sprintf("%-12s%-12s%-12s\n",
			"Ӣ����","������","����");
		msg += CYN"=========================================\n"NOR;
		for(i=0;i<num;i++)
		msg += sprintf("%-12s%-12s%-12s\n",
				data[i]["id"],
				data[i]["name"],
				F_MASTER->query_chinese_class(data[i]["class"]));
		msg += CYN"=========================================\n"NOR;
		tell_object(this_player(), msg);
		return 1;
	}
	
	if (arg == "2"){
		data = STATUS_D->query_riddle_list();
		num = sizeof(data);
		msg = HIR"	�����Ƕ������а�ǰ"+ chinese_number(num)+"��\n"NOR;
		msg += CYN"============================================\n"NOR;
		msg += sprintf("%-12s%-12s%-12s%-12s\n",
			"Ӣ����","������","����", "������");
		msg += CYN"============================================\n"NOR;
		for(i=0;i<num;i++)
		msg += sprintf("%-12s%-12s%-12s%-12s\n",
				data[i]["id"],
				data[i]["name"],
				F_MASTER->query_chinese_class(data[i]["class"]),
				skill_level(data[i]["r_num"]));
		msg += CYN"============================================\n"NOR;
		tell_object(this_player(), msg);
		return 1;
	}
	
	if (arg == "3") {
		tianjiao = this_player()->query("m_killer");
		tell_object(this_player(),WHT"\t����		�����콾¼��"+ this_player()->name(1)+ "��\n"NOR);
    	write(HIR BLK"������������������������������������������������������������������������������\n"NOR);
    	if (!tianjiao)	write (HIR "��\n"NOR);
    	else
    	{
			list = keys(tianjiao);
			i = 0;					// deal with the problem of setting riddle=0
			for(j=0; j<sizeof(list); j++)
			{
			    if (tianjiao[list[j]])
			 	{
			    	if(i%5!=4) 
						write(sprintf(YEL"%-16s"NOR,list[j]));
			    	else 
						write(YEL + list[j] + "\n"NOR);   
					i++;
				}
			}
    	}
		write(HIR BLK"\n������������������������������������������������������������������������������\n"NOR);
		return 1;
	}

	if (arg == "4"){
		file = "/doc/help/book/book_bai";
		read_book(file);
		return 1;
	}
	
	if (!arg)
		return notify_fail("��Ҫ����һ����ŵ��鼮��\n");
	
	tell_object(this_player(),"�����ʱû�������ŵ��鼮��\n");	
	return 1;
}
	
	
int	do_list(){
	write(CYN"�����������ŵ�ǰ������Ĵ��¡�
"WHT"	
	�������Ƹ��ְ�
	
	���������Ƕ��ǰ�
	
	���������콾¼��˽�У�
	
	��������������������

"CYN"
������ã���������������Ķ����Ӧ���鼮��

	\n"NOR);
	return 1;
}

int read_book(string file)
{
        int i;
        string map, *search;
        object ob;
        ob = this_player();
	
		if (ob->query_temp("timer/help_list")+1 > time())
			return notify_fail("����ϵͳ���ڻָ��У�����һ���ʹ�á�\n");
		
		ob->set_temp("timer/help_list",time());
	
		write(CLR);

		write(read_file(file+"_main"));		// Show the table		
		input_to("selete_main",ob,file);
		return 1;
}

void back_off(string num, object ob, string file)
{
		write(CLR);
        write(read_file(file+"_main"));
        input_to("selete_main", ob, file);
}

void quit_help(object ob)
{
     	write(HIC"\n ллʹ�÷����鼮�Ķ�ϵͳ��\n\n"NOR);
        return;
}


string page(string book, int page){

	 string *title;
	 	 	 	 
	 switch (book){
	 	case "bai":	title = book_bai; break;
		default: 	return "\\n\nû���Ȿ��\n";
	 }
	 
	 if (page> sizeof(title))
	 	return " \n\n��ҳ�����ڣ���ǰ�鼮����"+sizeof(title)+"ҳ���밴���������Ŀ¼��\n";
	 
	 return title[page-1];
}

void selete_main (string num, object ob, string file)
{        
        int number, total;
        string type, *data;
        string book;
               
	    if (ob->query_temp("timer/help_list")+2 > time())
        {
        	ob->add_temp("marks/repeat_help",1);
//        	CHANNEL_D->do_sys_channel(
//				"info",sprintf("%d",ob->query_temp("marks/repeat_help")));
        }	else
        	ob->delete_temp("marks/repeat_help");   
        
        if (ob->query_temp("marks/repeat_help")<4) {
	        ob->set_temp("timer/help_list",time()); 
	        
	        if (sscanf(num,"%d",number)== 1) {
	        	sscanf(file, "/doc/help/book/book_%s", book);
			}
	        if (book) {
	            if (number) {
	               	write(CLR);					
					write(HIW"\n����������������������������������������������������������������������[0m\n"NOR);
					write(page(book,number));
	               	write(sprintf(HIW"����������������������������������%-d����������������������������������\n"NOR,
							number));
	               	input_to("back_off",ob, file);	
	               	return;
		       	}else {
		    	    	quit_help(ob);
		        		return;	
		    	}
	        }
        }  

        ob->delete_temp("marks/repeat_help");    
       	quit_help(ob);
}
