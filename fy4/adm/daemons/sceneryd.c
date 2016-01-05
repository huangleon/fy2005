//��Ȼ���ۿ��Ʒ�����
//sceneryd.c
//������Ȼ���۷���

#define TIME_TICK (time())
#define CALL_OUT_TIME 720
#define RATE 100

#include <ansi.h>

inherit F_DBASE;
mapping *scenery_phase;
int date;
int get_date();
int is_newday();
void add_date();
void update_scenery_phase();
void scenery_happen(mapping scenery);
void init_scenery_phase();
int show_scenery_phase();
mapping *read_table(string file);

void create()
{
        seteuid(getuid());
        scenery_phase=read_table("/adm/etc/scenery_phase");
        set("channel_id", "���۾���");
        set("id","sceneryd");
        init_scenery_phase();
}

void init_scenery_phase()
{
        int i;
        date=NATURE_D->get_current_time()[2];
        for(i=0;i<sizeof(scenery_phase);i++)
        {
                scenery_phase[i]["happen"]=0;
                if(!stringp(catch(call_other(scenery_phase[i]["file"],"???"))))
                {
  			CHANNEL_D->do_sys_channel(
			"sys", sprintf("%s(%s)��������׼�����ˡ�mapping��%O\n",
	                scenery_phase[i]["name"],scenery_phase[i]["file"],scenery_phase[i]));

	         }
                else
                {
                        CHANNEL_D->do_sys_channel(
                        "sys",sprintf("%s(%s)���ۿ��������⣬�뾡���顣\n",
                        scenery_phase[i]["name"],scenery_phase[i]["file"]));
                }
        }
        call_out("update_scenery_phase",1);
}


void update_scenery_phase()
{
        int daytime,day;
        int i,success;
        int season;
        int begintime,time;
        remove_call_out("update_scenery_phase");
        CHANNEL_D->do_sys_channel(
           "sys","��ʼ����scenery_phase");
        CHANNEL_D->do_sys_channel(
           "sys",sprintf("��ǰ����%d,�ϴδ����������%d�������Ƿ���newday?%d",NATURE_D->get_current_time()[2],get_date(),is_newday()));
        if(is_newday())
        {


		date=NATURE_D->get_current_time()[2];
        	daytime=NATURE_D->get_current_time()[5];
        	for(i=0;i<sizeof(scenery_phase);i++)
        	{
// here need rewrite
	                if(scenery_phase[i][sprintf("%d",NATURE_D->get_season())]==1)//���ڶ�ͷ��
        	        {
                		day=NATURE_D->get_current_time()[2];
                		begintime=0;
				if(scenery_phase[i]["end"]<0) begintime=1440+scenery_phase[i]["end"];
//			�������ǲ�ȡ���ִ�����
//			���ȣ����ǰ���һ�죬Ҳ����24������Ϊһ��call_out�ļ��
//			��Σ����ǻ��ж��������ڣ�Ŀǰ���ڵ�ʱ���Ƿ����������ʱ�����Ǻ�
//			Ȼ���жϸ���
//			����Щ�������Ժ���ô��Ҫ������
//			�����ǰ���Щ���ʵ���
//			ok,let's do it
				if(begintime)//����������
				{
//����ǿ��Է�����ʱ��������ʱ��Ļ��������������ж�һ��Ŀǰ��ʱ�����ĸ�ʱ���֮�ڣ�Ŀǰ��������ʱ��Σ������ǿ��Է����ģ�һ���ǲ����Է�����
					if(daytime<scenery_phase[i]["begin"])//Ŀǰʱ�����ڵ�һ�����棬��ô�����ѡ����ʱ���е�һ��
					{
						if(random(2))//��ѡ��һ��ʱ��
							time=random(scenery_phase[i]["begin"]);
						else
							time=begintime+random(1440-begintime);
					}
					else // ok��ʵ����ֻҪʱ����˵�һ�Σ���ô����ֻ����ѡ�ڶ�����
					{
						time=begintime+random(1440-begintime);
					}
				}
				else//��һ��������
				{
//				if(scenery_phase[i]["begin"]<daytime
//		                && scenery_phase[i]["end"]>daytime)
				//���time�Ǵ�һ�쿪ʼ��������������������������ѡһ��ʱ��ν��У���ȻĿǰ��daytimeҲ�ü������ڣ��ں���call_out��ʱ��ʹ��
					time=scenery_phase[i]["begin"]+random(scenery_phase[i]["end"]-scenery_phase[i]["begin"]);
		        	}
                       		if(random(RATE)<scenery_phase[i]["rate"])//����������
                              	{
                                               	scenery_phase[i]["happen"]=1;//������Ϊ��Ҫ������
                                               	call_out("scenery_happen",time-daytime,scenery_phase[i]);
                               	}
                        //Ŷ�������и�СС��ʧ�󣬿�ʼд��ʱ��û���ǵ�������ʱ�䷢��
                        //��ô���ǽ�����һ����ı���
                	}
		}

	}
//	cot=CALL_OUT_TIME+random(CALL_OUT_TIME);
//      call_out("update_scenery_phase",cot);
	call_out("update_scenery_phase",CALL_OUT_TIME+random(CALL_OUT_TIME));
}

//����������ж��Ƿ������Ȼ���۵�
void scenery_happen(mapping scenery)
{
        object room;
        if(!objectp(room=find_object(scenery["file"])))
                room=load_object(scenery["file"]);
        CHANNEL_D->do_sys_channel("sys",
                   sprintf("%s(%s)�������ھ�Ҫ�����ˣ�����happen��%d��\n",
	           scenery["name"],scenery["file"],scenery["happen"]));
        room->init_scenery();
}

int show_scenery_phase()
{
	int i;
	for(i=0;i<sizeof(scenery_phase);i++)
        	write(sprintf("scenery_phase[%d] is %O\n",i,scenery_phase[i]));
        return 1;
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

int get_date()
{
	return date;
}

int is_newday()
{
 	return (get_date()!=NATURE_D->get_current_time()[2]);
}

void add_date()
{
	date++;
}